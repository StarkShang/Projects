var app = getApp();
var tool = require('../../utils/tools.js');
var timer;
var milliseconds = 0;

function clearSavedAlarm() {
    wx.getSavedFileList({
        success: function(res) {
            for (var i = 0; i < res.fileList.length; i++) {
                wx.removeSavedFile({
                    filePath: res.fileList[i].filePath
                });
            }
        }
    });
}
function saveAlarm(filePath) {
    wx.saveFile({
        tempFilePath: filePath,
        success: function(res) {
            app.UpdateAlarmUrl(res.savedFilePath);
        }
    });
}

Page({
    data: {
        status: 'start',
        time_text: '00:00 00'
    },
    StartRecord: function() {
        wx.startRecord({
          success: function(res){
            // 清除原始铃声
            clearSavedAlarm();
            saveAlarm(res.tempFilePath);
          }
        });
        timer = setInterval(this.intervalAction, 10);
        setTimeout(function() {
            wx.stopRecord();
            clearInterval(timer);
            this.setData({status: 'start'});
        }, 10000);
        this.setData({status: 'stop'});
    },
    StopRecord: function() {
        wx.stopRecord();
        clearInterval(timer);
        this.setData({status: 'start'});
    },
    // 定时器回调函数
    intervalAction: function() {
        milliseconds = milliseconds + 10;
        this.setData({time_text: tool.TimeFormat(milliseconds)});
    },

    onShow: function() {
        milliseconds = 0;
    },

    voicePlay: function() {
        wx.playVoice({ filePath: app.GetAlarmUrl() });
    },
    voicePause: function() {
        wx.pauseVoice();
    },
    voiceStop: function() {
        wx.stopVoice();
    }
});