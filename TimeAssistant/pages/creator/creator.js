var app = getApp();

Page({
  data: {
    steps: [{
      duration:'00:05',
      discreption:'60%浓度的酒精清洗'
    },{
      duration:'00:05',
      discreption:'70%浓度的酒精清洗'
    }],

    isSubmit: false,
    selectedIndex: -1,
    modalHidden: true,
    modalNoCancel: false,
    modalTitle: '添加步骤',
    modalTextareaPlaceholder: '添加该步骤的描述',
    modalConfirmText: '添加',
    duration: '00:00',
    discreption: '',
  },
  //事件处理函数
  StepDetail: function(e) {
    this.data.selectedIndex = e.currentTarget.id;
    this.setData({isSubmit: false});
    if (this.data.selectedIndex < this.data.steps.length) { // 对于已经添加的步骤
      var step = this.data.steps[e.currentTarget.id];
      this.setData({duration: step.duration, discreption: step.discreption});
      this.setData({modalNoCancel: true, modalTitle: '修改步骤', modalTextareaPlaceholder: '添加该步骤的描述', modalConfirmText: '修改'});
    } else { // 新建步骤
      this.setData({duration: '00:00', discreption: ''});
      this.setData({modalNoCancel: false, modalTitle: '添加步骤', modalTextareaPlaceholder: '添加该步骤的描述', modalConfirmText: '添加'});
    }
    this.setData({modalHidden: false});
  },

  // 模态框事件处理函数
  BindTimeChange: function(e) {
    this.setData({duration: e.detail.value});
  },
  BindTextChange: function(e) {
    this.setData({discreption: e.detail.value});
  },
  CancelAction: function() {
    this.setData({modalHidden: true});
  },
  ConfirmAction: function() {
    this.setData({modalHidden: true});
    if (this.data.isSubmit == true) { // 对于提交项目添加申请
      var app = getApp();
      app.projects.push({
        name: this.data.discreption,
        steps: this.data.steps
      });
      wx.reLaunch({
        url: '../index/index'
      })
    } else if (this.data.modalNoCancel == true) { // 对于修改步骤
      this.data.steps[this.data.selectedIndex] = {
        duration: this.data.duration,
        discreption:this.data.discreption
      };
      this.setData({steps: this.data.steps});
    } else { // 新建步骤
      this.data.steps.push({
        duration: this.data.duration,
        discreption:this.data.discreption
      });
      this.setData({steps: this.data.steps});
    }
  },

  // 添加按钮事件处理函数
  Submit: function() {
    this.setData({isSubmit: true});
    this.setData({modalNoCancel: false, modalTitle: '请输入项目标题',  discreption: '', modalTextareaPlaceholder: '项目标题', modalConfirmText: '添加'});
    this.setData({modalHidden: false});
  }
})