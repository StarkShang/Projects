var app = getApp();
var timer, project, projectIndex;
var stepIndex = 0;
var milliseconds = 0;



function DataFormat(time) {
    var micro_sec = Math.floor(time%1000/10);
    var seconds = Math.floor(time/1000);
    var hour = Math.floor(seconds/3600);
    var min  = Math.floor(seconds%36000/60);
    var sec  = Math.floor(seconds%60);
    return Completion(hour) + ":" + Completion(min) + ":" + Completion(sec) + " " + Completion(micro_sec);
}
function Completion(num) {
    return num<10 ? "0"+num : num;
}
function str2ms(str) {
    var arr = str.split(":");
    return (parseInt(arr[0])*60+parseInt(arr[1]))*1000;
}
function playAlarm() {

}
function stopAlarm() {

}
function remindUser() {
    var url = wx.getStorageSync(app.alarmFileKey);
    wx.playVoice({
        filePath: url,
        success: function() {
            var a = 1;
        },
        fail: function() {
            var b = 1;
        },
        complete: function() {
            remindUser();
        }
    });

    wx.showModal({
        title: '到点了',
        showCancel: false,
        success: function() {
            var a = 1;
        },
        fail: function() {
            var b = 1;
        },
        complete: function() {
            wx.stopVoice();
        }
    });
}

Page({
    data: {
        status: 'start',
        time_text: '00:00:00',
        worksteps: [
            {status: 'completing',index: 0,description: ''},
            {status: 'timing',index: 0,description: ''},
            {status: 'waiting',index: 0,description: ''}
        ]
    },
    StartCount: function(){
        this.setData({status: 'stop'});
        timer = setInterval(this.intervalAction, 10)
    },
    StopCount: function(){
        clearInterval(timer);
        this.setData({status: 'start'});
    },
    // 定时器回调函数
    intervalAction: function() {
        if (milliseconds < 1) { // 倒计时结束
            clearInterval(timer); // 清除定时器
            remindUser();
            
            // 载入下一步骤数据
            stepIndex = stepIndex + 1;
            this.loadStep(stepIndex);
            if (stepIndex < project.steps.length) {
                milliseconds = str2ms(project.steps[stepIndex].duration);
                this.setData({status: 'start'});
            } else {
                milliseconds = 0;
            }
        } else { // 倒计时没有结束
            milliseconds = milliseconds-10;
        }
        this.updateTime(milliseconds);
    },

    // 导航到项目设置页面
    Setting: function() {
        wx.navigateTo({
            url: '../creator/creator?index='+projectIndex+'&mode=modify'
        });
    },

    // 生命周期函数
    onLoad: function(e) {
        stepIndex = 0;
        projectIndex = e.index
        project = getApp().projects[projectIndex];
        this.loadStep(stepIndex);
        milliseconds = str2ms(project.steps[stepIndex].duration);
        this.updateTime(milliseconds);
    },

    // 工具函数
    loadStep: function(index) {
        var ws = new Array(3);
        for (var i = 0; i < 3; i++) {
            var nowIndex = index+i-1;
            if (nowIndex>=0 && nowIndex<project.steps.length) {
                ws[i] = {
                    status: this.data.worksteps[i].status,
                    index: nowIndex+1,
                    description: project.steps[nowIndex].description
                };
            } else {
                ws[i] = {
                    status: this.data.worksteps[i].status,
                    index: '', description: ''
                };
            }
        }
        this.setData({worksteps: ws});
    },
    updateTime: function(milliseconds) {
        this.setData({time_text: DataFormat(milliseconds)});
    }
});