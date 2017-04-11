function Completion(num) {
    return num<10 ? "0"+num : num;
}

function TimeFormat(ms) {
    var micro_sec = Math.floor(ms%1000/10);
    var seconds = Math.floor(ms/1000);
    var hour = Math.floor(seconds/3600);
    var min  = Math.floor(seconds%36000/60);
    var sec  = Math.floor(seconds%60);
    return Completion(min) + ":" + Completion(sec) + " " + Completion(micro_sec);
}

exports.TimeFormat = TimeFormat;