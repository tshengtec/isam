#ifndef GLOBALDEFINITION_H
#define GLOBALDEFINITION_H
#include <QString>

#define CONFIG_JSON_FILE_NAME "config.json"
#define GOODS_JSON_FILE_NAME "goods.json"
#define GOODS_DB_FILE_NAME "goods.db"

/*获取商品类别*/
#define GET_CATEGORY "/v1/category"

/*商品查询*/
#define GET_SHOP_GOODS "/v1/shop_goods"

#define PUSH_SALES_RECORD "/v1/sales_record"
static const QString goodsFields[] = {
    "id",        "categoryName",       "createdTime",        "goodsName",        "barCode"
};

static const QString goodsFieldsType[] = {
    "int",       "varchar",            "int",                     "varchar",              "varchar"
};

#define CREATE_DB_TABLE "create table person (id integer primary key, " \
                                            "categoryName varchar(20), " \
                                            "createdTime integer, " \
                                            "goodsName varchar(20), " \
                                            "barCode varchar(20))"
#endif // GLOBALDEFINITION_H
