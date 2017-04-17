var app = getApp();
var tool = require('../../utils/tools.js');
var timer, project, projectIndex;
var milliseconds = 0;
var isProjectCompleted = false;


function str2ms(str) {
    var arr = str.split(':');
    return (parseInt(arr[0])*60+parseInt(arr[1]))*1000;
}

var stopAlarm = false;
function playAlarm() {
    wx.playVoice({
        filePath: app.GetAlarmUrl(),
        complete: function() {
            if (!stopAlarm) {
                playAlarm();
            }
        }
    });
}
function remindUser() {
    wx.showModal({
        title: '到点了',
        showCancel: false,
        success: function() {
            stopAlarm = true;
            wx.stopVoice();
        }
    });
    stopAlarm = false;
    playAlarm();
    
}

Page({
    data: {
        countStatus: 'start',
        time_text: '00:00 00',
        stepIndex: 0,
        stepNumber: 0,
        worksteps: [
            {countStatus: 'completing',index: 0,description: ''},
            {countStatus: 'timing',index: 0,description: ''},
            {countStatus: 'waiting',index: 0,description: ''}
        ]
    },

    startStopwatch: function() {
        timer = setInterval(this.intervalAction, 10);
        this.setData({countStatus: 'stop'});
    },
    stopStopwatch: function() {
        clearInterval(timer);
        this.setData({countStatus: 'start'});
    },
    StopwatchEvent: function(){
        if (isProjectCompleted) return;
        this.data.countStatus=='start'?this.startStopwatch():this.stopStopwatch();
    },
    // 定时器回调函数
    intervalAction: function() {
        // Case 1: Counting
        if (milliseconds > 0) {
            milliseconds = milliseconds-10;
        }
        // Case 2: Time over
        else {
            this.stopStopwatch();
            remindUser();

            // case 2.1: project not complete
            if (this.data.stepIndex + 1 < project.steps.length) {
                // load the data of next step
                this.setData({stepIndex: this.data.stepIndex+1});
                this.loadStep(this.data.stepIndex);
                milliseconds = str2ms(project.steps[this.data.stepIndex].duration);
            } 
            // case 2.2: project complete
            else {
                milliseconds = 0;
                isProjectCompleted = true;
            }
        }

        // Update time label
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
        projectIndex = e.index
    },
    onShow: function() {
        project = getApp().projects[projectIndex];
        this.setData({
            stepIndex: 0,
            stepNumber: project.steps.length
        })
        isProjectCompleted = false;
        this.loadStep(this.data.stepIndex);
        milliseconds = this.data.stepNumber > 0 ? str2ms(project.steps[this.data.stepIndex].duration) : 0;
        this.updateTime(milliseconds);
    },

    // 工具函数
    loadStep: function(index) {
        var ws = new Array(3);
        for (var i = 0; i < 3; i++) {
            var nowIndex = index+i-1;
            if (nowIndex>=0 && nowIndex<project.steps.length) {
                ws[i] = {
                    countStatus: this.data.worksteps[i].countStatus,
                    index: nowIndex+1,
                    description: project.steps[nowIndex].description
                };
            } else {
                ws[i] = {
                    countStatus: this.data.worksteps[i].countStatus,
                    index: '', description: ''
                };
            }
        }
        this.setData({worksteps: ws});
    },
    updateTime: function(milliseconds) {
        this.setData({time_text: tool.TimeFormat(milliseconds)});
    }
});