//index.js
//获取应用实例
var app = getApp();

Page({
  data: {
    projects: app.projects,
    temp: 1
  },
  //事件处理函数
  ProjectDetail: function() {
    wx.navigateTo({
      url: '../detail/detail'
    })
  },
  CreateProject: function() {
    wx.navigateTo({
      url: '../creator/creator'
    })
  }
})
