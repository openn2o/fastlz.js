# fastlz.js #
this is data compress lib for javascript.

## install ##


> npm install fastlz.js


## example ##
    var fs   = require("fs");
    var path = "./need.js";
    var data = fs.readFileSync(path);
    
    setTimeout(function () {
    	var decoder = new FastLZDecoder();
    	var test = new Uint8Array(data);
    	var buffer  = decoder.encode(test);
    	var start = 2650074;
    	var end   = start+ 30;
    	var buffer2  = decoder.decode(new Uint8Array(buffer));
    	fs.writeFileSync("invalidate.js", buffer2);
    	fs.writeFileSync("compress.js", buffer);
    }, 500);


it always run powerful. 

agent.zy@aliyun.com