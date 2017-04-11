//app.js
App({
  projectKey: 'project',
  projects: [],
  alarmFileKey: 'alarm',
  onLaunch: function () {
    //调用API从本地缓存中获取数据
    this.projects = wx.getStorageSync(this.projectKey);
  }
})