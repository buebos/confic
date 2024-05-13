#include "../include/core.h"

Confic config = {
    .name = "sample",
    .root = &(ConficNode){
        .attributes = (ConficNodeAttribute[]){
            {
                .key = "compiler",
                .is_nullable = false,
                .type = CONFIC_NODE,
                .schema = {
                    .node = &(ConficNode){
                        .attributes = (ConficNodeAttribute[]){
                            {
                                .key = "command",
                                .type = CONFIC_STR,
                                .is_nullable = false,
                                .schema = {
                                    .str = &(ConficStr){
                                        .enumeration = NULL,
                                    },
                                },
                            },
                            {
                                .key = "args",
                                .type = CONFIC_ARRAY,
                                .is_nullable = false,
                                .schema = {
                                    .array = &(ConficArray){
                                        .type = CONFIC_STR,
                                        .len_range = NULL,
                                        .element_schema = NULL,
                                    },
                                },
                            },
                            NULL,
                        },
                    },
                },
            },
            {
                .key = "finder",
                .is_nullable = true,
                .type = CONFIC_NODE,
                .schema = &(ConficSchema){
                    .node = &(ConficNode){
                        .attributes = (ConficNodeAttribute[]){
                            {
                                .key = "entry",
                                .is_nullable = true,
                                .type = CONFIC_NODE,
                                .schema = &(ConficSchema){
                                    .node = &(ConficNode){
                                        .attributes = (ConficNodeAttribute[]){
                                            {
                                                .key = "fileid",
                                                .is_nullable = true,
                                                .type = CONFIC_BOOLEAN,
                                                .schema = NULL,
                                            },
                                            NULL,
                                        },
                                    },
                                },
                            },
                            NULL,
                        },
                    },
                },
            },
            {
                .key = "scripts",
                .is_nullable = true,
                .type = CONFIC_MAP,
                .schema = {
                    .map = &(ConficMap){
                        .value_type = CONFIC_STR,
                        .value_schema = NULL,
                        .len_range = NULL,
                    },
                },
            },
            {
                .key = "build",
                .is_nullable = true,
                .type = CONFIC_NODE,
                .schema = {
                    .node = &(ConficNode){
                        .attributes = (ConficNodeAttribute[]){
                            {
                                .key = "entry",
                                .is_nullable = true,
                                .type = CONFIC_STR,
                                .schema = NULL,
                            },
                            {
                                .key = "target",
                                .is_nullable = true,
                                .type = CONFIC_STR,
                                .schema = NULL,
                            },
                            {
                                .key = "defines",
                                .is_nullable = true,
                                .type = CONFIC_ARRAY,
                                .schema = &(ConficSchema){
                                    .array = &(ConficArray){
                                        .type = CONFIC_STR,
                                        .len_range = NULL,
                                        .element_schema = NULL,
                                    },
                                },
                            },
                            {
                                .key = "resolver",
                                .is_nullable = true,
                                .type = CONFIC_NODE,
                                .schema = &(ConficSchema){
                                    .node = &(ConficNode){
                                        .attributes = (ConficNodeAttribute[]){
                                            {
                                                .key = "searches",
                                                .is_nullable = true,
                                                .type = CONFIC_ARRAY,
                                                .schema = &(ConficSchema){
                                                    .array = &(ConficArray){
                                                        .type = CONFIC_STR,
                                                        .len_range = NULL,
                                                        .element_schema = NULL,
                                                    },
                                                },
                                            },
                                            {
                                                .key = "shortcut",
                                                .is_nullable = true,
                                                .type = CONFIC_STR,
                                                .schema = &(ConficSchema){
                                                    .str = &(ConficStr){
                                                        .enumeration = &(ConficNodeEnumConstraint){
                                                            .elements = (char*[]){
                                                                "RELATIVE",
                                                                "PARALLEL",
                                                                "PARAFLAT",
                                                            },
                                                        },
                                                    },
                                                },
                                            },
                                            NULL,
                                        },
                                    },
                                },
                            },
                            {
                                .key = "out",
                                .is_nullable = true,
                                .type = CONFIC_NODE,
                                .schema = &(ConficSchema){
                                    .node = &(ConficNode){
                                        .attributes = (ConficNodeAttribute[]){
                                            {
                                                .key = "dir",
                                                .is_nullable = true,
                                                .type = CONFIC_STR,
                                                .schema = NULL,
                                            },
                                            {
                                                .key = "tempdir",
                                                .is_nullable = true,
                                                .type = CONFIC_STR,
                                                .schema = NULL,
                                            },
                                            {
                                                .key = "filename",
                                                .is_nullable = true,
                                                .type = CONFIC_STR,
                                                .schema = NULL,
                                            },
                                            NULL,
                                        },
                                    },
                                },
                            },
                            {
                                .key = "copies",
                                .is_nullable = true,
                                .type = CONFIC_ARRAY,
                                .schema = &(ConficSchema){
                                    .array = &(ConficArray){
                                        .type = CONFIC_NODE,
                                        .len_range = NULL,
                                        .element_schema = &(ConficSchema){
                                            .node = &(ConficNode){
                                                .attributes = (ConficNodeAttribute[]){
                                                    {
                                                        .key = "from",
                                                        .is_nullable = false,
                                                        .type = CONFIC_STR,
                                                        .schema = NULL,
                                                    },
                                                    {
                                                        .key = "to",
                                                        .is_nullable = false,
                                                        .type = CONFIC_STR,
                                                        .schema = NULL,
                                                    },
                                                    NULL,
                                                },
                                            },
                                        },
                                    },
                                },
                            },
                            {
                                .key = "source",
                                .is_nullable = true,
                                .type = CONFIC_NODE,
                                .schema = &(ConficSchema){
                                    .node = &(ConficNode){
                                        .attributes = (ConficNodeAttribute[]){
                                            {
                                                .key = "excludes",
                                                .is_nullable = false,
                                                .type = CONFIC_ARRAY,
                                                .schema = &(ConficSchema){
                                                    .array = &(ConficArray){
                                                        .type = CONFIC_STR,
                                                        .len_range = NULL,
                                                        .element_schema = NULL,
                                                    },
                                                },
                                            },
                                            {
                                                .key = "includes",
                                                .is_nullable = false,
                                                .type = CONFIC_ARRAY,
                                                .schema = &(ConficSchema){
                                                    .array = &(ConficArray){
                                                        .type = CONFIC_STR,
                                                        .len_range = NULL,
                                                        .element_schema = NULL,
                                                    },
                                                },
                                            },
                                            NULL,
                                        },
                                    },
                                },
                            },
                            {
                                .key = "lib",
                                .is_nullable = true,
                                .type = CONFIC_NODE,
                                .schema = &(ConficSchema){
                                    .node = &(ConficNode){
                                        .attributes = (ConficNodeAttribute[]){
                                            {
                                                .key = "statics",
                                                .is_nullable = true,
                                                .type = CONFIC_ARRAY,
                                                .schema = &(ConficSchema){
                                                    .array = &(ConficArray){
                                                        .type = CONFIC_STR,
                                                        .len_range = NULL,
                                                        .element_schema = NULL,
                                                    },
                                                },
                                            },
                                            {
                                                .key = "dynamics",
                                                .is_nullable = true,
                                                .type = CONFIC_ARRAY,
                                                .schema = &(ConficSchema){
                                                    .array = &(ConficArray){
                                                        .type = CONFIC_STR,
                                                        .len_range = NULL,
                                                        .element_schema = NULL,
                                                    },
                                                },
                                            },
                                            NULL,
                                        },
                                    },
                                },
                            },
                            {
                                .key = "variants",
                                .is_nullable = true,
                                .type = CONFIC_ARRAY,
                                .schema = &(ConficSchema){
                                    .array = &(ConficArray){
                                        .type = CONFIC_NODE,
                                        .len_range = NULL,
                                        .element_schema = &(ConficSchema){
                                            .node = &(ConficNode){
                                                .attributes = (ConficNodeAttribute[]){
                                                    {
                                                        .key = "name",
                                                        .is_nullable = false,
                                                        .type = CONFIC_STR,
                                                        .schema = NULL,
                                                    },
                                                    {
                                                        .key = "defines",
                                                        .is_nullable = true,
                                                        .type = CONFIC_ARRAY,
                                                        .schema = &(ConficSchema){
                                                            .array = &(ConficArray){
                                                                .type = CONFIC_STR,
                                                                .len_range = NULL,
                                                                .element_schema = NULL,
                                                            },
                                                        },
                                                    },
                                                    NULL,
                                                },
                                            },
                                        },
                                    },
                                },
                            },
                            NULL,
                        },
                    },
                },
            },
            NULL,
        },
    },
};