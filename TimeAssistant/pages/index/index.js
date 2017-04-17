//index.js
//获取应用实例
var app = getApp();
var stopTapEvent = false;
Page({
  data: {
    projects: [],
    selectedId: -1,
  },
  
  //事件处理函数
  // 导航到项目运行页面
  ProjectDetail: function(e) {
    if (!stopTapEvent) {
      var index = e.currentTarget.id;
      wx.navigateTo({
        url: '../detail/detail?index='+index
      });
    }
    stopTapEvent = false;
  },
  DeleteProject: function(e) {
    var index = e.currentTarget.dataset.projectid;
    app.DeleteProjects(this.data.projects[index]);
    this.setData({projects: app.projects});
  },

  // 导航到项目创建页面
  CreateProject: function() {
    wx.navigateTo({
      url: '../creator/creator?index=-1&mode=create'
    });
  },
  SettingAlarm: function() {
    wx.navigateTo({
      url: '../record/record'
    });
  },
  
  /** 生命周期处理函数 **/
  onShow: function() {
    this.setData({projects: app.projects});
  }
})
