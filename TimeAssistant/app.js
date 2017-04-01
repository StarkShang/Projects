//app.js
App({
  onLaunch: function () {
    //调用API从本地缓存中获取数据
    var logs = wx.getStorageSync('logs') || []
    logs.unshift(Date.now())
    wx.setStorageSync('logs', logs)
  },
  projects: [{
    name: '去脂滴实验',
    steps: [{
      duration:'00:05',
      discreption:'60%浓度的酒精清洗'
    },{
      duration:'00:05',
      discreption:'70%浓度的酒精清洗'
    }]},{
    name: '去脂滴实验2',
    steps: [{
      duration:'00:05',
      discreption:'60%浓度的酒精清洗'
    },{
      duration:'00:05',
      discreption:'70%浓度的酒精清洗'
    }]}]
})