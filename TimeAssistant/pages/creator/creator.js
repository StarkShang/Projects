var app = getApp();
var project,projectIndex,projectName;
var selectedIndex,workMode;
const createMode = 'create';
const modifyMode = 'modify';

function defineText(str) {
  return str==''?'未定义':str;
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
  // 删除步骤
  DelItem: function(e) {
    var index = e.currentTarget.id.split('-')[1];
    var tempSteps = this.data.steps;
    tempSteps.splice(index,1);
    this.setData({
      steps: tempSteps
    });
  },
  // 创建、修改步骤
  StepDetail: function(e) {
    selectedIndex = e.currentTarget.id;
    selectedIndex<this.data.steps.length?this.modifyStep(selectedIndex):this.createStep();
  },
  // 提交项目
  SubmitAction: function() {
    this.submitProject();
  },

  /** 模态框事件处理函数 **/
  // Modify the duration of the step 
  BindTimeChange: function(e) {
    this.setData({'step.duration': e.detail.value});
  },
  // Modify the description of the step
  BindTextChange: function(e) {
    this.setData({'step.description': defineText(e.detail.value)});
  },
  // Cancel modal dialog
  CancelAction: function() {
    this.hiddenModal();
  },
  // Confirm modal dialog
  ConfirmAction: function() {
    this.hiddenModal();
    if (this.data.modalOpts.submit == true) { // for submitting project
      // Update the projects
      app.UpdateProjects({
        name: defineText(this.data.step.description),
        steps: this.data.steps
      }, projectIndex);
      // Navigate back to previous page
      wx.navigateBack({ delta: 1 });
    } else { // for submitting step
      if (selectedIndex < this.data.steps.length) { // for modifying step info
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
    } 
  },

  /** 生命周期函数 **/
  onLoad: function(e) {
    workMode = e.mode;
    projectIndex = e.index;
    switch(workMode) {
      case createMode:
        wx.setNavigationBarTitle({title: '新建项目'});
        break;
      case modifyMode:
        wx.setNavigationBarTitle({title: '修改项目'});
        project = app.projects[projectIndex];
        projectName = project.name;
        this.setData({steps: project.steps});
        break;
      default:
        wx.navigateBack({ delta: 1 });
    }
  },

  /** 工具函数 **/
  createStep: function() {
    this.setData({
      step: { duration: '00:00', description: '' },
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
  submitProject: function() {
    this.setData({
      step: {
        duration: '00:00',
        description: workMode==createMode?'':projectName
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
  hiddenModal: function() {
    this.setData({'modalOpts.hidden': true});
  }
})