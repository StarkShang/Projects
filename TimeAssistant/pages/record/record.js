var app = getApp();
var filePath;

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
            wx.setStorage({
                key: app.alarmFileKey,
                data: res.savedFilePath
            });
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
            var tempFilePath = res.tempFilePath;
            wx.playVoice({ filePath: tempFilePath });
            filePath = tempFilePath;
            // 清除原始铃声
            clearSavedAlarm();
            saveAlarm(tempFilePath);
          }
        });
        setTimeout(function() {
            wx.stopRecord();
        }, 5000);
        this.setData({status: 'stop'});
    },
    StopRecord: function() {
        this.setData({status: 'start'});
    },

    voicePlay: function() {
        var url = wx.getStorageSync(app.alarmFileKey);
        wx.playVoice({ filePath: filePath });
    },
    voicePause: function() {
        wx.pauseVoice();
    },
    voiceStop: function() {
        wx.stopVoice();
    }
});