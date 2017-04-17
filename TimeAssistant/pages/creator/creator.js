var app = getApp();
var projectIndex,oldProjectName;
var selectedIndex,workMode;
const createMode = 'create';
const modifyMode = 'modify';

function defineText(str) {
  return str==''?'未定义':str;
}

Page({
  data: {
    project: {},
    submitStepDialog: {
      title: '',
      confirmText: '',
      hidden: true
    },
    projectDialogHidden: true,
    step: {
      duration: '00:00',
      description: ''
    }
  },

  /** 界面绑定事件处理函数 **/
  // 删除步骤
  DeleteStep: function(e) {
    var index = e.currentTarget.dataset.stepid;
    var tempSteps = this.data.project.steps;
    tempSteps.splice(index,1);
    this.setData({
      'project.steps': tempSteps
    });
  },

  /** Events about submitting step **/
  ShowStepDailog: function(e) {
    selectedIndex = e.currentTarget.id;
    selectedIndex<0 ? this.createStep():this.modifyStep(selectedIndex);
  },
  /** Events about step dialog **/
  SubmitStep: function() {
    this.HideStepDialog();
    var tempSteps = this.data.project.steps;
    // for creating a step
    if (selectedIndex < 0) {
      tempSteps.push(this.data.step);
    } else { // for create step info
      tempSteps[selectedIndex] = this.data.step;
    }
    this.setData({'project.steps': tempSteps});
  },
  HideStepDialog: function() {
    this.setData({'submitStepDialog.hidden': true});
  },
  // Modify the duration of the step 
  BindTimeChange: function(e) {
    this.setData({'step.duration': e.detail.value});
  },
  // Modify the description of the step
  BindTextChange: function(e) {
    this.setData({'step.description': e.detail.value});
  },

  /** Events about submitting project **/
  ShowProjectDailog: function() {
    oldProjectName = this.data.project.name;
    this.setData({ projectDialogHidden: false });
  },
  /** Events about project dialog **/
  SubmitProject: function() {
    workMode == createMode ? app.CreateProject(this.data.project) : app.UpdateProject(this.data.project);
    // Navigate back to previous page
    wx.navigateBack({ delta: 1 });
  },
  HideProjectDialog: function() {
    this.setData({projectDialogHidden: true});
  },
  ChangeProjectTitle: function(e) {
    this.setData({'project.name': e.detail.value});
  },

  /** 生命周期函数 **/
  onLoad: function(e) {
    workMode = e.mode;
    projectIndex = e.index;

    switch(workMode) {
      case createMode:
        this.setData({project: {name:'',steps: []}});
        wx.setNavigationBarTitle({title: '新建项目'});
        break;
      case modifyMode:
        this.setData({project: app.projects[projectIndex]});
        wx.setNavigationBarTitle({title: this.data.project.name});        
        break;
      default:
        wx.navigateBack({ delta: 1 });
    }
  },

  /** 工具函数 **/
  createStep: function() {
    this.setData({
      step: { duration: '00:00', description: '' },
      submitStepDialog: {
        title: '添加步骤',
        confirmText: '添加',
        hidden: false,
      }
    });
  },
  modifyStep: function(selectedIndex) {
    this.setData({
      step: this.data.project.steps[selectedIndex],
      submitStepDialog: {
        title: '修改步骤',
        confirmText: '修改',
        hidden: false,
      }
    });
  }
})