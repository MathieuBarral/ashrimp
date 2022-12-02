#ifndef ASHRIMP_TABLE_H
    #define ASHRIMP_TABLE_H

    #define COMMENT_SYMBOL '#'
    #define FUNCTION_SYMB ':'
    #define LABEL_SYMB '$'
    #define ARGS_SEPARATOR_SYMBOL ','

    #define TABLE_SIZE 9
    #define MAX_ARGS 3

    // Instructions opcodes enum
    typedef enum ashrimp_fc_type_s {
        ASHRMP_FC_ADD = 0xbb,
        ASHRMP_FC_MUL,
        ASHRMP_FC_DIV,
        ASHRMP_FC_SET,
        ASHRMP_FC_CMP,
        ASHRMP_FC_JMP,
        ASHRMP_FC_JMPIF,
        ASHRMP_FC_WRITE,
        ASHRMP_FC_HALT
    } ashrimp_fc_type_t;

    // Variables opcodes enum
    typedef enum ashrimp_args_type_s {
        ASHRMP_ARGS_REG = 0xc4,
        ASHRMP_ARGS_INT,
        ASHRMP_ARGS_LABEL,
        ASHRMP_ARGS_NULL
    } ashrimp_args_type_t;

    // Instruction table template structure
    typedef struct ashrimp_table_s {
        char *ashrimp_name;
        ashrimp_fc_type_t type;
        int args_nb;
        int fc_size;
        ashrimp_args_type_t args_list[MAX_ARGS];
    } ashrimp_table_t;

    // Instruction table
    static ashrimp_table_t ashrimp_table[TABLE_SIZE] = {
        {"add", ASHRMP_FC_ADD, 3, 7, {ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_REG}
        },
        {"mul", ASHRMP_FC_MUL, 3, 7, {ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_REG}
        },
        {"div", ASHRMP_FC_DIV, 3, 7, {ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_REG}
        },
        {"set", ASHRMP_FC_SET, 2, 5, {ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_REG}
        },
        {"cmp", ASHRMP_FC_CMP, 2, 5, {ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG,
                                    ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG}
        },
        {"jmp", ASHRMP_FC_JMP, 1, 3, {ASHRMP_ARGS_LABEL}},
        {"jmpif", ASHRMP_FC_JMPIF, 1, 3, {ASHRMP_ARGS_LABEL}},
        {"write", ASHRMP_FC_WRITE, 1, 3, {ASHRMP_ARGS_INT | ASHRMP_ARGS_LABEL | ASHRMP_ARGS_REG}},
        {"halt", ASHRMP_FC_HALT, 0, 1, {ASHRMP_ARGS_NULL}}
    };

#endif