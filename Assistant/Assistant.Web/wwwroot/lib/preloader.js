var preHash;

document.onselectstart = function () {
    //alert("onselectstart")
     return false;
 }

 document.oncontextmenu = function () {
     //alert("oncontextmenu")
     return false;
 }

 document.onselectstart = function () {
     //alert("onselectstart")
     return false;
 }

document.oncopy = function() {
    //alert("oncopy")
    document.selection.empty();
}

document.onbeforecopy= function() {
    //alert("onbeforecopy")
    return false;
}

window.onload = function() {
    //alert("onload")

    setTimeout(function () {
        preHash = sjcl.hash.sha256.hash(document.documentElement.outerHTML);
        console.log(preHash);
    }, 500);
}

//var timeId = window.setInterval(function () {
//    var newHash = sjcl.hash.sha256.hash(document.documentElement.outerHTML);
//    e = true;
//    for (var i=0;i<8;i++) { e = e && (preHash[i] == newHash[i]); }
//    if (!e) {
//        console.log("不要修改代码");
//    }
//}, 1000);