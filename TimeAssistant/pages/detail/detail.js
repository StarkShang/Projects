var app = getApp();
var tool = require('../../utils/tools.js');
var timer, project, projectIndex;
var milliseconds = 0;


function str2ms(str) {
    var arr = str.split(':');
    return (parseInt(arr[0])*60+parseInt(arr[1]))*1000;
}

function remindUser() {
    wx.playVoice({
        filePath: app.GetAlarmUrl(),
        complete: function() {
            remindUser();
        }
    });

    wx.showModal({
        title: '到点了',
        showCancel: false,
        success: function() {
            wx.stopVoice();
        }
    });
}

Page({
    data: {
        status: 'start',
        time_text: '00:00 00',
        stepIndex: 0,
        stepNumber: 0,
        worksteps: [
            {status: 'completing',index: 0,description: ''},
            {status: 'timing',index: 0,description: ''},
            {status: 'waiting',index: 0,description: ''}
        ]
    },
    StartCount: function(){
        this.setData({status: 'stop'});
        timer = setInterval(this.intervalAction, 10);
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
            this.setData({stepIndex: this.data.stepIndex+1});
            this.loadStep(this.data.stepIndex);
            if (this.data.stepIndex < project.steps.length) {
                milliseconds = str2ms(project.steps[this.data.stepIndex].duration);
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
        projectIndex = e.index
    },
    onShow: function() {
        project = getApp().projects[projectIndex];
        this.setData({
            stepIndex: 0,
            stepNumber: project.steps.length
        })
        this.loadStep(this.data.stepIndex);
        milliseconds = str2ms(project.steps[this.data.stepIndex].duration);
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
        this.setData({time_text: tool.TimeFormat(milliseconds)});
    }
});