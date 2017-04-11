//app.js
const projectKey = 'project';
const alarmKey   = 'alarm';

App({
  projects: [],

  /** 函数 **/
  LoadProjects: function() {
    this.projects = wx.getStorageSync(projectKey);
  },
  UpdateProjects: function(project, index) {
    if (index>=0&&index<this.projects.length) {
      this.projects[index] = project;
    } else {
      this.projects.push(project);
    }
    // store the projects
    wx.setStorage({
      key: projectKey,
      data: this.projects
    });
  },
  RemoveProjects: function(index, length) {
    this.projects.splice(index,length);
    // store the projects
    wx.setStorage({
      key: projectKey,
      data: this.projects
    });
  },

  GetAlarmUrl: function() {
    return wx.getStorageSync(alarmKey);
  },
  UpdateAlarmUrl: function(alarmFilePath) {
    wx.setStorage({
      key: alarmKey,
      data: alarmFilePath
    })
  }
})