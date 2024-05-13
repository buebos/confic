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
                                    .strnode = &(ConficStr){
                                        .enumeration = NULL,
                                    },
                                },
                            },
                            {
                                .key = "args",
                                .type = CONFIC_STR,
                                .is_nullable = true,
                                .schema = &(ConficArray){
                                    .type = CONFIC_STR,
                                    .len_range = NULL,
                                    .element_schema = NULL,
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
                .schema = &(ConficNodeSchema){
                    .node = &(ConficNode){
                        .attributes = &(ConficNodeAttribute[]){
                            {
                                .key = "entry",
                                .is_nullable = true,
                                .type = CONFIC_NODE,
                                .schema = &(ConficNodeSchema){
                                    .node = &(ConficNode){
                                        .attributes = &(ConficNodeAttribute[]){
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
                NULL,
            },
            {
                .key = "scripts",
            },
            NULL,
        },
    },
};