#include <stdint.h>
#include <stdio.h>
#include <malloc.h>
#include "../include/functions.h"

typedef enum{
	INT2,
	INT4,
	INT8,
	INT16,
	INT32,
	INT64,
	uINT2,
	uINT4,
	uINT8,
	uINT16,
	uINT32,
	uINT64,
	CHAR,
	STR,
	f4,
	f8,
	f16,
	f32,
	f64,
	ARR,
	HASH,
}prismVariableType;

typedef struct{
	prismVariableType type;	
	size_t size;
	void* data;
}prismVariable;


// init functions
prismVariable assign_variable(prismVariableType type, void* data){
	prismVariable newVariable;
	newVariable.type = type;
	switch(type){
		case INT2:
			newVariable.data = (int16_t*)malloc(sizeof(int16_t));
			break;
		case INT4:
			newVariable.data = (int32_t*)malloc(sizeof(int32_t));
			break;
		case INT8:
			newVariable.data = (int64_t*)malloc(sizeof(int64_t));
			break;
		case INT16:
			newVariable.data = (int64_t*)malloc(sizeof(int128_t));
			break;
		case INT32:
			newVariable.data = (int64_t*)malloc(sizeof(int256_t));
			break;
		case INT64:
			newVariable.data = (int64_t*)malloc(sizeof(int256_t));
			break;
		case uINT2:
			newVariable.data = (uint16_t*)malloc(sizeof(uint16_t));
			break;
		case uINT4:
			newVariable.data = (uint32_t*)malloc(sizeof(uint32_t));
			break;
		case uINT8:
			newVariable.data = (uint64_t*)malloc(sizeof(uint64_t));
			break;
		case uINT16:
			newVariable.data = (uint64_t*)malloc(sizeof(uint128_t));
            break;
		case uINT32:
			newVariable.data = (uint64_t*)malloc(sizeof(uint256_t));
            break;
		case uINT64:
			newVariable.data = (uint64_t*)malloc(sizeof(uint512_t));
			break;
		case CHAR:
			newVariable.data = (char*)malloc(sizeof(char));
			break;
		case STR:
			newVariable.data = (char*)malloc(sizeof(char*)*2);
			break;
		case f4:
			break;
		case f8:
			break;
		case f16:
			break;
		case f32:
			break;
		case f64:
			break;
		case ARR:
			break;
		case HASH:
			break;
		default:
			newVariable.data = malloc(sizeof(int)*2);
			break;
	}
}


// make enums readable
const char* prismVariableType_to_string(prismVariableType type){
	switch(type){
		case INT2:
			return "INT2";
			break;
		case INT4:
			return "INT4";
			break;
		case INT8:
			return "INT8";
			break;
		case INT16:
			return "INT16";
			break;
		case INT32:
			return "INT32";
			break;
		case INT64:
			return "INT64";
			break;
		case uINT2:
			return "uINT2";
			break;
		case uINT4:
			return "uINT4";
			break;
		case uINT8:
			return "uINT8";
			break;
		case uINT16:
			return "uINT16";
            break;
		case uINT32:
			return "uINT32";
            break;
		case uINT64:
			return "uINT64";
			break;
		case CHAR:
			return "CHAR";
			break;
		case STR:
			return "STR";
			break;
		case f4:
			return "f4";
			break;
		case f8:
			return "f8";
			break;
		case f16:
			return "f16";
			break;
		case f32:
			return "f32";
			break;
		case f64:
			return "f64";
			break;
		case ARR:
			return "ARR";
			break;
		case HASH:
			return "HASH";
			break;
		default:
			return "mystery type";
			break;
	}
}
