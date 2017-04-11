var app = getApp();
var project,projectIndex,selectedIndex,mode;
function defineText(str) {
  return str==""?"未定义":str;
}

Page({
  data: {
    steps: [],
    modalOpts: {
      title: '',
      textareaPlaceholder: '',
      confirmText: '',
      noCancel: false,
      hidden: true,
      submit: false
    },
    step: {
      duration: '00:00',
      description: ''
    }
  },
  /** 界面绑定事件处理函数 **/
  StepDetail: function(e) {
    selectedIndex = e.currentTarget.id;
    selectedIndex<this.data.steps.length?this.modifyStep(selectedIndex):this.createStep();
  },
  // 添加按钮事件处理函数
  SubmitAction: function() {
    mode=="create" ? this.createProject():this.modifyProject();
  },
  DelItem: function(e) {
    var index = e.currentTarget.id.split("-")[1];
    var tempSteps = this.data.steps;
    tempSteps.splice(index,1);
    this.setData({
      steps: tempSteps
    });
  },

  /** 模态框事件处理函数 **/
  // 步骤时间 
  BindTimeChange: function(e) {
    var tempStep = this.data.step;
    tempStep.duration = e.detail.value;
    this.setData({step: tempStep});
  },
  // 步骤描述
  BindTextChange: function(e) {
    var tempStep = this.data.step;
    tempStep.description = defineText(e.detail.value);
    this.setData({step: tempStep});
  },
  CancelAction: function() {
    this.hiddenModal();
  },
  ConfirmAction: function() {
    this.hiddenModal();
    if (this.data.modalOpts.submit == true) { // 对于提交项目添加申请
      app.projects.push({
        name: defineText(this.data.step.description),
        steps: this.data.steps
      });
      // 进行缓存
      wx.setStorage({
        key: app.projectKey,
        data: app.projects
      });
      wx.navigateBack({ delta: 1 });
    } else if (selectedIndex < this.data.steps.length) { // 对于修改步骤
      var tempSteps = this.data.steps;
      tempSteps[selectedIndex] = this.data.step;
      this.setData({steps: tempSteps});
    } else { // 新建步骤
      var tempSteps = this.data.steps;
      tempSteps.push({
        duration: this.data.step.duration,
        description: defineText(this.data.step.description)
      });
      this.setData({steps: tempSteps});
    }
  },

  // 生命周期函数
  onLoad: function(e) {
    mode = e.mode;
    projectIndex = e.index;
    if (mode == 'create') {
      wx.setNavigationBarTitle({title: '新建项目'});
    } else if (mode == 'modify') {
      wx.setNavigationBarTitle({title: '修改项目'});
      project = app.projects[projectIndex];
      this.setData({steps: project.steps});
    }
  },

  /** 工具函数 **/
  createStep: function() {
    this.setData({
      step: {
        duration: '00:00',
        description: ''
      },
      modalOpts: {
        title: '添加步骤',
        textareaPlaceholder: '添加该步骤的描述',
        confirmText: '添加',
        noCancel: false,
        hidden: false,
        submit: false
      }
    });
  },
  modifyStep: function(selectedIndex) {
    this.setData({
      step: this.data.steps[selectedIndex],
      modalOpts: {
        title: '修改步骤',
        textareaPlaceholder: '添加该步骤的描述',
        confirmText: '修改',
        noCancel: true,
        hidden: false,
        submit: false
      }
    });
  },
  createProject: function() {
    this.setData({
      step: {
        duration: '00:00',
        description: ''
      },
      modalOpts: {
        title: '请输入项目标题',
        textareaPlaceholder: '项目标题',
        confirmText: '添加',
        noCancel: false,
        hidden: false,
        submit: true
      }
    });
  },
  modifyProject: function() {
    app.projects[projectIndex].steps = this.data.steps;
    wx.setStorage({
      key: app.projectKey,
      data: app.projects
    });
    wx.navigateBack({ delta: 1 });
  },
  hiddenModal: function() {
    var opts = this.data.modalOpts;
    opts.hidden = true;
    this.setData({modalOpts: opts});
  }
})