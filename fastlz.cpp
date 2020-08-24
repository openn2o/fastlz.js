/***
* 安装包管理工具
*/
#include <cheerp/client.h>
#include <cheerp/types.h>

#define uint8 unsigned char
#define size_t unsigned long long
#define _STATIC_CAST_ __builtin_cheerp_make_regular
#define __MAX_FILE_SIZE__ 1024*1024*10
#define DEBUG 1
using namespace client;

	#include <stdio.h>
	#include "fastlz.h"
	#include "fastlz.c"
/*extern "C" {
	#include <stdio.h>
	#include "fastlz.h"
	#include "fastlz.c"
};*/

/**
*    对外接口
*/
class  [[cheerp::jsexport]] FastLZDecoder {
	private:
	
	public:
	FastLZDecoder(){};
	/**
	*  解析视频标签
	*  client::Uint8Array -> int
	*/
	ArrayBufferView *  
	encode (client::Uint8Array * buff) {
		size_t len = buff->get_length(); 
		uint8 *p = _STATIC_CAST_<uint8>(buff, 0);
	
		uint8 * output = (uint8*) malloc(len + 1);
		fastlz_compress_level(1, p, len, output);
		int result = fastlz_compress(p, len, output);
		
		client::Number * n = new client::Number(result);	
		uint8 * output2 = (uint8*) malloc(result);
		memcpy(output2, output, result);
		
		free(output);
		return cheerp::MakeArrayBufferView(output2);
	}
	
	
	ArrayBufferView *  
	decode (client::Uint8Array * buff) {
		
		size_t len = buff->get_length();
		
		#if DEBUG == 1 
		console.log("decode start");
		client::Number* debug_1 = new client::Number(len);
		console.log(debug_1 -> toString());
		#endif
		
		uint8 *p = _STATIC_CAST_<uint8>(buff, 0);
		uint8 * output = (uint8*) malloc(__MAX_FILE_SIZE__);
		int result = fastlz_decompress(p, len, output, __MAX_FILE_SIZE__);
		#if DEBUG == 1 
		client::Number* debug_2 = new client::Number(result);
		console.log(debug_2 -> toString());
		console.log("decode end");
		#endif
	
		uint8 * output2 = (uint8*) malloc(result);
		memcpy(output2, output, result);
		free(output);
		
		return cheerp::MakeArrayBufferView(output2);
	}
	
};


void webMain() {
	
}