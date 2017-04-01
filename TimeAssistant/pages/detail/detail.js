var app = getApp();
var timer;
Page({
    data: {
        project: app.projects[0],
        time: app.projects[0].steps[0].duration,
        time1: 10
    },
    onLoad: function(){
        timer = setInterval(this.sb, 1000)
    },
    sb: function() {
        if (this.data.time1<1) {
            clearInterval(timer);
        } else {
            var now = this.data.time1;
            this.setData({time1: now-1});
        }
    }
})