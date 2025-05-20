#include <stdint.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
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
	F5_3,
	F8_23_FLOAT,
	F10_42,
	F11_52_DOUBLE,
	F14_71,
	ARR,
	HASH,
}prismVariableType;

typedef struct{
	prismVariableType type;	
	size_t size;
	void** data;
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
		case F5_3:
			newVariable.data = (f5_3*)malloc(sizeof(f5_3));
			break;
		case F8_23_FLOAT:
			newVariable.data = (f8_23_float*)malloc(sizeof(f8_23_float));
			break;
		case F10_42:
			newVariable.data = (f10_42*)malloc(sizeof(f10_42));
			break;
		case F11_52_DOUBLE:
			newVariable.data = (f11_52_double*)malloc(sizeof(f11_52_double));
			break;
		case F14_71:
			newVariable.data = (f14_71*)malloc(sizeof(f14_71));
			break;
		case ARR:
			newVariable.data = (prismVariable*)malloc(sizeof(prismVariable)*5);
			break;
		case HASH:
			newVariable.data = (void**)malloc(sizeof(void*)*2);
			newVariable.data[0] = (char*)malloc(sizeof(char*)*5);
			newVariable.data[1] = (void*)malloc(sizeof(void*)*5);
			break;
		default:
			newVariable.data = malloc(sizeof(int)*2);
			fprintf(stderr, "Critical Memory Error: Memory corruption of type prismVariableType at %p: %d/", &assign_variable, type);
			break;
	}
}


// make enums readable
char* prismVariableType_to_string(prismVariableType type){
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
		case F5_3:
			return "F5_3";
			break;
		case F8_23_FLOAT:
			return "f8_23FLOAT";
			break;
		case F10_42:
			return "F10_42";
			break;
		case F11_52_DOUBLE:
			return "f11_52DOUBLE";
			break;
		case F14_71:
			return "F14_71";
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
