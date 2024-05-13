#ifndef __CONFIC_CORE_H__

#define __CONFIC_CORE_H__

#include <stdbool.h>
#include <stdlib.h>

typedef union ConficNodeSchema ConficNodeSchema;
typedef struct ConficNodeAttribute ConficNodeAttribute;
typedef struct ConficNode ConficNode;

typedef enum ConficNodeType {
    CONFIC_BOOLEAN,

    CONFIC_INT,
    CONFIC_FLOAT,

    CONFIC_STR,

    CONFIC_ARRAY,
    CONFIC_MAP,

    CONFIC_NODE,
} ConficNodeType;

typedef struct ConficNodeRangeConstraint {
    int lower_limit;
    int upper_limit;
} ConficNodeRangeConstraint;

typedef struct ConficNodeEnumConstraint {
    char **elements;
} ConficNodeEnumConstraint;

typedef struct ConficInt {
    int _value;
    ConficNodeRangeConstraint *range;
} ConficInt;

typedef struct ConficFloat {
    float _value;
    ConficNodeRangeConstraint *range;
} ConficFloat;

typedef struct ConficStr {
    char *_value;
    ConficNodeEnumConstraint *enumeration;
} ConficStr;

typedef struct ConficArray {
    ConficNodeType type;
    ConficNodeSchema element_schema;
    ConficNodeRangeConstraint *len_range;

    ConficNodeAttribute *_elements;
} ConficArray;

typedef struct ConficMap {
    ConficNodeType value_type;
    ConficNodeSchema *value_schema;
    ConficNodeRangeConstraint *len_range;

    ConficNodeAttribute *_entries;
} ConficMap;

typedef union ConficNodeSchema {
    ConficInt *intnode;
    ConficFloat *floatnode;
    ConficStr *strnode;
    ConficArray *arraynode;
    ConficMap *map;
    ConficNode *node;
} ConficNodeSchema;

typedef struct ConficNodeAttribute {
    char *key;
    bool is_nullable;
    ConficNodeType type;
    ConficNodeSchema schema;
} ConficNodeAttribute;

typedef struct ConficNode {
    ConficNodeAttribute *attributes;
} ConficNode;

typedef struct Confic {
    char *name;
    ConficNode *root;
} Confic;

#endif  // !__CONFIC_CORE_H__