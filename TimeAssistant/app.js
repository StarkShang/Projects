//app.js
const projectKey = 'project';
const alarmKey   = 'alarm';

App({
  projects: [],
  onLaunch: function(options) {
    var res = wx.getStorageInfoSync();
    if (res.keys.indexOf(projectKey)!=-1) {
      this.projects = wx.getStorageSync(projectKey);
    }
  },
  onHide: function() {
    wx.setStorageSync(projectKey, this.projects);
  },

  /** 函数 **/
  CreateProject: function(project) {
    // Check the project name
    var query = this.RetrieveProject(project.name);
    if (query == null) {
      this.projects.push(project);
      return true;
    } else { // a project with same name has already exsited
      return false;
    }
  },
  RetrieveProject: function(projectName) {
    for (var index=0; index<this.projects.length; index++) {
      if (this.projects[index].name == projectName) {
        return this.projects[index];
      }
    }
    return null;
  },
  UpdateProject: function(project) {
    // Check the project name
    var query = this.RetrieveProject(project.name);
    if (query == null) {
      return false;
    } else { // a project with same name has already exsited
      query.name = project.name;
      query.steps = project.steps;
      return true;
    }
  },
  DeleteProjects: function(project) {
    var query = this.RetrieveProject(project.name);
    if (query != null) {
      var index = this.projects.indexOf(query);
      this.projects.splice(index,1);
    }
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