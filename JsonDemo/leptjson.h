//
// Created by zzh0838 on 2022/8/26.
//

#ifndef JSONDEMO_LEPTJSON_H
#define JSONDEMO_LEPTJSON_H

#endif //JSONDEMO_LEPTJSON_H


//因为 C 语言没有 C++ 的命名空间（namespace）功能，一般会使用项目的简写作为标识符的前缀。
typedef enum {
    LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT
} lept_type;

//json 解析成一个树形结构,lept_value 是树形结构的一个节点
typedef struct {
    lept_type type;
} lept_value;


//lept_parse 返回值
enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR
};

int lept_parse(lept_value *v, const char *json);

//获取结果的类型
lept_type lept_get_type(const lept_value *v);