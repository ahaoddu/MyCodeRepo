//
// Created by zzh0838 on 2022/8/26.
//

#include "leptjson.h"
#include <assert.h>
#include <stddef.h>

#define EXPECT(c, ch)       do { assert(*c->json == (ch)); c->json++; } while(0)

typedef struct {
    const char *json;
} lept_context;


static int lept_parse_true(lept_context *c, lept_value *ptr);

static void lept_parse_whitespace(lept_context *c) {
    const char *p = c->json;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
        p++;
    c->json = p;
}

/* null  = "null" */
static int lept_parse_null(lept_context *c, lept_value *v) {
    EXPECT(c, 'n');
    if (c->json[0] != 'u' || c->json[1] != 'l' || c->json[2] != 'l')
        return LEPT_PARSE_INVALID_VALUE;
    c->json += 3;
    v->type = LEPT_NULL;
    return LEPT_PARSE_OK;
}

static int lept_parse_true(lept_context *c, lept_value *v) {
    EXPECT(c, 't');
    if (c->json[0] != 'r' || c->json[1] != 'u' || c->json[2] != 'e')
        return LEPT_PARSE_INVALID_VALUE;
    c->json += 3;
    v->type = LEPT_TRUE;
    return LEPT_PARSE_OK;
}

static int lept_parse_false(lept_context *c, lept_value *v) {
    EXPECT(c, 'f');
    if (c->json[0] != 'a' || c->json[1] != 'l' || c->json[2] != 's' || c->json[3] != 'e')
        return LEPT_PARSE_INVALID_VALUE;
    c->json += 4;
    v->type = LEPT_FALSE;
    return LEPT_PARSE_OK;
}

/* value = null / false / true */
/* 提示：下面代码没处理 false / true，将会是练习之一 */
static int lept_parse_value(lept_context *c, lept_value *v) {
    switch (*c->json) {
        case 'n':
            return lept_parse_null(c, v);
        case 't':
            return lept_parse_true(c, v);
        case 'f':
            return lept_parse_false(c, v);
        case '\0':
            return LEPT_PARSE_EXPECT_VALUE;
        default:
            return LEPT_PARSE_INVALID_VALUE;
    }
}


/**
 *
 * @param v  lept_value 的内存空间又调用者分配
 * @param json
 * @return
 */
int lept_parse(lept_value *v, const char *json) {
    lept_context context;
    assert(v != NULL);
    context.json = json;
    v->type = LEPT_NULL; //默认类型时 NULL
    lept_parse_whitespace(&context);
    int ret = lept_parse_value(&context, v);
    //处理 LEPT_PARSE_ROOT_NOT_SINGULAR
    if (ret == LEPT_PARSE_OK) {
        lept_parse_whitespace(&context);
        if(*context.json != '\0') {
            return LEPT_PARSE_ROOT_NOT_SINGULAR;
        }
    }

    return ret;
}

//获取结果的类型
lept_type lept_get_type(const lept_value *v) {
    return v->type;
}