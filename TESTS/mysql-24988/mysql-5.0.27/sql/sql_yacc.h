/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END_OF_INPUT = 258,
     ABORT_SYM = 259,
     ACTION = 260,
     ADD = 261,
     ADDDATE_SYM = 262,
     AFTER_SYM = 263,
     AGAINST = 264,
     AGGREGATE_SYM = 265,
     ALGORITHM_SYM = 266,
     ALL = 267,
     ALTER = 268,
     ANALYZE_SYM = 269,
     AND_AND_SYM = 270,
     AND_SYM = 271,
     ANY_SYM = 272,
     AS = 273,
     ASC = 274,
     ASCII_SYM = 275,
     ASENSITIVE_SYM = 276,
     ATAN = 277,
     AUTO_INC = 278,
     AVG_ROW_LENGTH = 279,
     AVG_SYM = 280,
     BACKUP_SYM = 281,
     BEFORE_SYM = 282,
     BEGIN_SYM = 283,
     BENCHMARK_SYM = 284,
     BERKELEY_DB_SYM = 285,
     BIGINT = 286,
     BINARY = 287,
     BINLOG_SYM = 288,
     BIN_NUM = 289,
     BIT_AND = 290,
     BIT_OR = 291,
     BIT_SYM = 292,
     BIT_XOR = 293,
     BLOB_SYM = 294,
     BOOLEAN_SYM = 295,
     BOOL_SYM = 296,
     BOTH = 297,
     BTREE_SYM = 298,
     BY = 299,
     BYTE_SYM = 300,
     CACHE_SYM = 301,
     CALL_SYM = 302,
     CASCADE = 303,
     CASCADED = 304,
     CAST_SYM = 305,
     CHAIN_SYM = 306,
     CHANGE = 307,
     CHANGED = 308,
     CHARSET = 309,
     CHAR_SYM = 310,
     CHECKSUM_SYM = 311,
     CHECK_SYM = 312,
     CIPHER_SYM = 313,
     CLIENT_SYM = 314,
     CLOSE_SYM = 315,
     COALESCE = 316,
     CODE_SYM = 317,
     COLLATE_SYM = 318,
     COLLATION_SYM = 319,
     COLUMNS = 320,
     COLUMN_SYM = 321,
     COMMENT_SYM = 322,
     COMMITTED_SYM = 323,
     COMMIT_SYM = 324,
     COMPACT_SYM = 325,
     COMPRESSED_SYM = 326,
     CONCAT = 327,
     CONCAT_WS = 328,
     CONCURRENT = 329,
     CONDITION_SYM = 330,
     CONNECTION_SYM = 331,
     CONSISTENT_SYM = 332,
     CONSTRAINT = 333,
     CONTAINS_SYM = 334,
     CONTINUE_SYM = 335,
     CONVERT_SYM = 336,
     CONVERT_TZ_SYM = 337,
     COUNT_SYM = 338,
     CREATE = 339,
     CROSS = 340,
     CUBE_SYM = 341,
     CURDATE = 342,
     CURRENT_USER = 343,
     CURSOR_SYM = 344,
     CURTIME = 345,
     DATABASE = 346,
     DATABASES = 347,
     DATA_SYM = 348,
     DATETIME = 349,
     DATE_ADD_INTERVAL = 350,
     DATE_SUB_INTERVAL = 351,
     DATE_SYM = 352,
     DAY_HOUR_SYM = 353,
     DAY_MICROSECOND_SYM = 354,
     DAY_MINUTE_SYM = 355,
     DAY_SECOND_SYM = 356,
     DAY_SYM = 357,
     DEALLOCATE_SYM = 358,
     DECIMAL_NUM = 359,
     DECIMAL_SYM = 360,
     DECLARE_SYM = 361,
     DECODE_SYM = 362,
     DEFAULT = 363,
     DEFINER_SYM = 364,
     DELAYED_SYM = 365,
     DELAY_KEY_WRITE_SYM = 366,
     DELETE_SYM = 367,
     DESC = 368,
     DESCRIBE = 369,
     DES_DECRYPT_SYM = 370,
     DES_ENCRYPT_SYM = 371,
     DES_KEY_FILE = 372,
     DETERMINISTIC_SYM = 373,
     DIRECTORY_SYM = 374,
     DISABLE_SYM = 375,
     DISCARD = 376,
     DISTINCT = 377,
     DIV_SYM = 378,
     DOUBLE_SYM = 379,
     DO_SYM = 380,
     DROP = 381,
     DUAL_SYM = 382,
     DUMPFILE = 383,
     DUPLICATE_SYM = 384,
     DYNAMIC_SYM = 385,
     EACH_SYM = 386,
     ELSEIF_SYM = 387,
     ELT_FUNC = 388,
     ENABLE_SYM = 389,
     ENCLOSED = 390,
     ENCODE_SYM = 391,
     ENCRYPT = 392,
     END = 393,
     ENGINES_SYM = 394,
     ENGINE_SYM = 395,
     ENUM = 396,
     EQ = 397,
     EQUAL_SYM = 398,
     ERRORS = 399,
     ESCAPED = 400,
     ESCAPE_SYM = 401,
     EVENTS_SYM = 402,
     EXECUTE_SYM = 403,
     EXISTS = 404,
     EXIT_SYM = 405,
     EXPANSION_SYM = 406,
     EXPORT_SET = 407,
     EXTENDED_SYM = 408,
     EXTRACT_SYM = 409,
     FALSE_SYM = 410,
     FAST_SYM = 411,
     FETCH_SYM = 412,
     FIELD_FUNC = 413,
     FILE_SYM = 414,
     FIRST_SYM = 415,
     FIXED_SYM = 416,
     FLOAT_NUM = 417,
     FLOAT_SYM = 418,
     FLUSH_SYM = 419,
     FORCE_SYM = 420,
     FOREIGN = 421,
     FORMAT_SYM = 422,
     FOR_SYM = 423,
     FOUND_SYM = 424,
     FRAC_SECOND_SYM = 425,
     FROM = 426,
     FROM_UNIXTIME = 427,
     FULL = 428,
     FULLTEXT_SYM = 429,
     FUNCTION_SYM = 430,
     FUNC_ARG0 = 431,
     FUNC_ARG1 = 432,
     FUNC_ARG2 = 433,
     FUNC_ARG3 = 434,
     GE = 435,
     GEOMCOLLFROMTEXT = 436,
     GEOMETRYCOLLECTION = 437,
     GEOMETRY_SYM = 438,
     GEOMFROMTEXT = 439,
     GEOMFROMWKB = 440,
     GET_FORMAT = 441,
     GLOBAL_SYM = 442,
     GRANT = 443,
     GRANTS = 444,
     GREATEST_SYM = 445,
     GROUP = 446,
     GROUP_CONCAT_SYM = 447,
     GROUP_UNIQUE_USERS = 448,
     GT_SYM = 449,
     HANDLER_SYM = 450,
     HASH_SYM = 451,
     HAVING = 452,
     HELP_SYM = 453,
     HEX_NUM = 454,
     HIGH_PRIORITY = 455,
     HOSTS_SYM = 456,
     HOUR_MICROSECOND_SYM = 457,
     HOUR_MINUTE_SYM = 458,
     HOUR_SECOND_SYM = 459,
     HOUR_SYM = 460,
     IDENT = 461,
     IDENTIFIED_SYM = 462,
     IDENT_QUOTED = 463,
     IF = 464,
     IGNORE_SYM = 465,
     IMPORT = 466,
     INDEXES = 467,
     INDEX_SYM = 468,
     INFILE = 469,
     INNER_SYM = 470,
     INNOBASE_SYM = 471,
     INOUT_SYM = 472,
     INSENSITIVE_SYM = 473,
     INSERT = 474,
     INSERT_METHOD = 475,
     INTERVAL_SYM = 476,
     INTO = 477,
     INT_SYM = 478,
     INVOKER_SYM = 479,
     IN_SYM = 480,
     IS = 481,
     ISOLATION = 482,
     ISSUER_SYM = 483,
     ITERATE_SYM = 484,
     JOIN_SYM = 485,
     KEYS = 486,
     KEY_SYM = 487,
     KILL_SYM = 488,
     LABEL_SYM = 489,
     LANGUAGE_SYM = 490,
     LAST_INSERT_ID = 491,
     LAST_SYM = 492,
     LE = 493,
     LEADING = 494,
     LEAST_SYM = 495,
     LEAVES = 496,
     LEAVE_SYM = 497,
     LEFT = 498,
     LEVEL_SYM = 499,
     LEX_HOSTNAME = 500,
     LIKE = 501,
     LIMIT = 502,
     LINEFROMTEXT = 503,
     LINES = 504,
     LINESTRING = 505,
     LOAD = 506,
     LOCAL_SYM = 507,
     LOCATE = 508,
     LOCATOR_SYM = 509,
     LOCKS_SYM = 510,
     LOCK_SYM = 511,
     LOGS_SYM = 512,
     LOG_SYM = 513,
     LONGBLOB = 514,
     LONGTEXT = 515,
     LONG_NUM = 516,
     LONG_SYM = 517,
     LOOP_SYM = 518,
     LOW_PRIORITY = 519,
     LT = 520,
     MAKE_SET_SYM = 521,
     MASTER_CONNECT_RETRY_SYM = 522,
     MASTER_HOST_SYM = 523,
     MASTER_LOG_FILE_SYM = 524,
     MASTER_LOG_POS_SYM = 525,
     MASTER_PASSWORD_SYM = 526,
     MASTER_PORT_SYM = 527,
     MASTER_POS_WAIT = 528,
     MASTER_SERVER_ID_SYM = 529,
     MASTER_SSL_CAPATH_SYM = 530,
     MASTER_SSL_CA_SYM = 531,
     MASTER_SSL_CERT_SYM = 532,
     MASTER_SSL_CIPHER_SYM = 533,
     MASTER_SSL_KEY_SYM = 534,
     MASTER_SSL_SYM = 535,
     MASTER_SYM = 536,
     MASTER_USER_SYM = 537,
     MATCH = 538,
     MAX_CONNECTIONS_PER_HOUR = 539,
     MAX_QUERIES_PER_HOUR = 540,
     MAX_ROWS = 541,
     MAX_SYM = 542,
     MAX_UPDATES_PER_HOUR = 543,
     MAX_USER_CONNECTIONS_SYM = 544,
     MEDIUMBLOB = 545,
     MEDIUMINT = 546,
     MEDIUMTEXT = 547,
     MEDIUM_SYM = 548,
     MERGE_SYM = 549,
     MICROSECOND_SYM = 550,
     MIGRATE_SYM = 551,
     MINUTE_MICROSECOND_SYM = 552,
     MINUTE_SECOND_SYM = 553,
     MINUTE_SYM = 554,
     MIN_ROWS = 555,
     MIN_SYM = 556,
     MLINEFROMTEXT = 557,
     MODE_SYM = 558,
     MODIFIES_SYM = 559,
     MODIFY_SYM = 560,
     MOD_SYM = 561,
     MONTH_SYM = 562,
     MPOINTFROMTEXT = 563,
     MPOLYFROMTEXT = 564,
     MULTILINESTRING = 565,
     MULTIPOINT = 566,
     MULTIPOLYGON = 567,
     MUTEX_SYM = 568,
     NAMES_SYM = 569,
     NAME_SYM = 570,
     NATIONAL_SYM = 571,
     NATURAL = 572,
     NCHAR_STRING = 573,
     NCHAR_SYM = 574,
     NDBCLUSTER_SYM = 575,
     NE = 576,
     NEW_SYM = 577,
     NEXT_SYM = 578,
     NONE_SYM = 579,
     NOT2_SYM = 580,
     NOT_SYM = 581,
     NOW_SYM = 582,
     NO_SYM = 583,
     NO_WRITE_TO_BINLOG = 584,
     NULL_SYM = 585,
     NUM = 586,
     NUMERIC_SYM = 587,
     NVARCHAR_SYM = 588,
     OFFSET_SYM = 589,
     OJ_SYM = 590,
     OLD_PASSWORD = 591,
     ON = 592,
     ONE_SHOT_SYM = 593,
     ONE_SYM = 594,
     OPEN_SYM = 595,
     OPTIMIZE = 596,
     OPTION = 597,
     OPTIONALLY = 598,
     OR2_SYM = 599,
     ORDER_SYM = 600,
     OR_OR_SYM = 601,
     OR_SYM = 602,
     OUTER = 603,
     OUTFILE = 604,
     OUT_SYM = 605,
     PACK_KEYS_SYM = 606,
     PARTIAL = 607,
     PASSWORD = 608,
     PARAM_MARKER = 609,
     PHASE_SYM = 610,
     POINTFROMTEXT = 611,
     POINT_SYM = 612,
     POLYFROMTEXT = 613,
     POLYGON = 614,
     POSITION_SYM = 615,
     PRECISION = 616,
     PREPARE_SYM = 617,
     PREV_SYM = 618,
     PRIMARY_SYM = 619,
     PRIVILEGES = 620,
     PROCEDURE = 621,
     PROCESS = 622,
     PROCESSLIST_SYM = 623,
     PURGE = 624,
     QUARTER_SYM = 625,
     QUERY_SYM = 626,
     QUICK = 627,
     RAID_0_SYM = 628,
     RAID_CHUNKS = 629,
     RAID_CHUNKSIZE = 630,
     RAID_STRIPED_SYM = 631,
     RAID_TYPE = 632,
     RAND = 633,
     READS_SYM = 634,
     READ_SYM = 635,
     REAL = 636,
     RECOVER_SYM = 637,
     REDUNDANT_SYM = 638,
     REFERENCES = 639,
     REGEXP = 640,
     RELAY_LOG_FILE_SYM = 641,
     RELAY_LOG_POS_SYM = 642,
     RELAY_THREAD = 643,
     RELEASE_SYM = 644,
     RELOAD = 645,
     RENAME = 646,
     REPAIR = 647,
     REPEATABLE_SYM = 648,
     REPEAT_SYM = 649,
     REPLACE = 650,
     REPLICATION = 651,
     REQUIRE_SYM = 652,
     RESET_SYM = 653,
     RESOURCES = 654,
     RESTORE_SYM = 655,
     RESTRICT = 656,
     RESUME_SYM = 657,
     RETURNS_SYM = 658,
     RETURN_SYM = 659,
     REVOKE = 660,
     RIGHT = 661,
     ROLLBACK_SYM = 662,
     ROLLUP_SYM = 663,
     ROUND = 664,
     ROUTINE_SYM = 665,
     ROWS_SYM = 666,
     ROW_COUNT_SYM = 667,
     ROW_FORMAT_SYM = 668,
     ROW_SYM = 669,
     RTREE_SYM = 670,
     SAVEPOINT_SYM = 671,
     SECOND_MICROSECOND_SYM = 672,
     SECOND_SYM = 673,
     SECURITY_SYM = 674,
     SELECT_SYM = 675,
     SENSITIVE_SYM = 676,
     SEPARATOR_SYM = 677,
     SERIALIZABLE_SYM = 678,
     SERIAL_SYM = 679,
     SESSION_SYM = 680,
     SET = 681,
     SET_VAR = 682,
     SHARE_SYM = 683,
     SHIFT_LEFT = 684,
     SHIFT_RIGHT = 685,
     SHOW = 686,
     SHUTDOWN = 687,
     SIGNED_SYM = 688,
     SIMPLE_SYM = 689,
     SLAVE = 690,
     SMALLINT = 691,
     SNAPSHOT_SYM = 692,
     SOUNDS_SYM = 693,
     SPATIAL_SYM = 694,
     SPECIFIC_SYM = 695,
     SQLEXCEPTION_SYM = 696,
     SQLSTATE_SYM = 697,
     SQLWARNING_SYM = 698,
     SQL_BIG_RESULT = 699,
     SQL_BUFFER_RESULT = 700,
     SQL_CACHE_SYM = 701,
     SQL_CALC_FOUND_ROWS = 702,
     SQL_NO_CACHE_SYM = 703,
     SQL_SMALL_RESULT = 704,
     SQL_SYM = 705,
     SQL_THREAD = 706,
     SSL_SYM = 707,
     STARTING = 708,
     START_SYM = 709,
     STATUS_SYM = 710,
     STD_SYM = 711,
     STDDEV_SAMP_SYM = 712,
     STOP_SYM = 713,
     STORAGE_SYM = 714,
     STRAIGHT_JOIN = 715,
     STRING_SYM = 716,
     SUBDATE_SYM = 717,
     SUBJECT_SYM = 718,
     SUBSTRING = 719,
     SUBSTRING_INDEX = 720,
     SUM_SYM = 721,
     SUPER_SYM = 722,
     SUSPEND_SYM = 723,
     SYSDATE = 724,
     TABLES = 725,
     TABLESPACE = 726,
     TABLE_SYM = 727,
     TEMPORARY = 728,
     TEMPTABLE_SYM = 729,
     TERMINATED = 730,
     TEXT_STRING = 731,
     TEXT_SYM = 732,
     TIMESTAMP = 733,
     TIMESTAMP_ADD = 734,
     TIMESTAMP_DIFF = 735,
     TIME_SYM = 736,
     TINYBLOB = 737,
     TINYINT = 738,
     TINYTEXT = 739,
     TO_SYM = 740,
     TRAILING = 741,
     TRANSACTION_SYM = 742,
     TRIGGER_SYM = 743,
     TRIGGERS_SYM = 744,
     TRIM = 745,
     TRUE_SYM = 746,
     TRUNCATE_SYM = 747,
     TYPES_SYM = 748,
     TYPE_SYM = 749,
     UDF_RETURNS_SYM = 750,
     UDF_SONAME_SYM = 751,
     ULONGLONG_NUM = 752,
     UNCOMMITTED_SYM = 753,
     UNDEFINED_SYM = 754,
     UNDERSCORE_CHARSET = 755,
     UNDO_SYM = 756,
     UNICODE_SYM = 757,
     UNION_SYM = 758,
     UNIQUE_SYM = 759,
     UNIQUE_USERS = 760,
     UNIX_TIMESTAMP = 761,
     UNKNOWN_SYM = 762,
     UNLOCK_SYM = 763,
     UNSIGNED = 764,
     UNTIL_SYM = 765,
     UPDATE_SYM = 766,
     UPGRADE_SYM = 767,
     USAGE = 768,
     USER = 769,
     USE_FRM = 770,
     USE_SYM = 771,
     USING = 772,
     UTC_DATE_SYM = 773,
     UTC_TIMESTAMP_SYM = 774,
     UTC_TIME_SYM = 775,
     VAR_SAMP_SYM = 776,
     VALUES = 777,
     VALUE_SYM = 778,
     VARBINARY = 779,
     VARCHAR = 780,
     VARIABLES = 781,
     VARIANCE_SYM = 782,
     VARYING = 783,
     VIEW_SYM = 784,
     WARNINGS = 785,
     WEEK_SYM = 786,
     WHEN_SYM = 787,
     WHERE = 788,
     WHILE_SYM = 789,
     WITH = 790,
     WORK_SYM = 791,
     WRITE_SYM = 792,
     X509_SYM = 793,
     XA_SYM = 794,
     XOR = 795,
     YEARWEEK = 796,
     YEAR_MONTH_SYM = 797,
     YEAR_SYM = 798,
     ZEROFILL = 799,
     TABLE_REF_PRIORITY = 800,
     ELSE = 801,
     THEN_SYM = 802,
     CASE_SYM = 803,
     BETWEEN_SYM = 804,
     NEG = 805
   };
#endif
#define END_OF_INPUT 258
#define ABORT_SYM 259
#define ACTION 260
#define ADD 261
#define ADDDATE_SYM 262
#define AFTER_SYM 263
#define AGAINST 264
#define AGGREGATE_SYM 265
#define ALGORITHM_SYM 266
#define ALL 267
#define ALTER 268
#define ANALYZE_SYM 269
#define AND_AND_SYM 270
#define AND_SYM 271
#define ANY_SYM 272
#define AS 273
#define ASC 274
#define ASCII_SYM 275
#define ASENSITIVE_SYM 276
#define ATAN 277
#define AUTO_INC 278
#define AVG_ROW_LENGTH 279
#define AVG_SYM 280
#define BACKUP_SYM 281
#define BEFORE_SYM 282
#define BEGIN_SYM 283
#define BENCHMARK_SYM 284
#define BERKELEY_DB_SYM 285
#define BIGINT 286
#define BINARY 287
#define BINLOG_SYM 288
#define BIN_NUM 289
#define BIT_AND 290
#define BIT_OR 291
#define BIT_SYM 292
#define BIT_XOR 293
#define BLOB_SYM 294
#define BOOLEAN_SYM 295
#define BOOL_SYM 296
#define BOTH 297
#define BTREE_SYM 298
#define BY 299
#define BYTE_SYM 300
#define CACHE_SYM 301
#define CALL_SYM 302
#define CASCADE 303
#define CASCADED 304
#define CAST_SYM 305
#define CHAIN_SYM 306
#define CHANGE 307
#define CHANGED 308
#define CHARSET 309
#define CHAR_SYM 310
#define CHECKSUM_SYM 311
#define CHECK_SYM 312
#define CIPHER_SYM 313
#define CLIENT_SYM 314
#define CLOSE_SYM 315
#define COALESCE 316
#define CODE_SYM 317
#define COLLATE_SYM 318
#define COLLATION_SYM 319
#define COLUMNS 320
#define COLUMN_SYM 321
#define COMMENT_SYM 322
#define COMMITTED_SYM 323
#define COMMIT_SYM 324
#define COMPACT_SYM 325
#define COMPRESSED_SYM 326
#define CONCAT 327
#define CONCAT_WS 328
#define CONCURRENT 329
#define CONDITION_SYM 330
#define CONNECTION_SYM 331
#define CONSISTENT_SYM 332
#define CONSTRAINT 333
#define CONTAINS_SYM 334
#define CONTINUE_SYM 335
#define CONVERT_SYM 336
#define CONVERT_TZ_SYM 337
#define COUNT_SYM 338
#define CREATE 339
#define CROSS 340
#define CUBE_SYM 341
#define CURDATE 342
#define CURRENT_USER 343
#define CURSOR_SYM 344
#define CURTIME 345
#define DATABASE 346
#define DATABASES 347
#define DATA_SYM 348
#define DATETIME 349
#define DATE_ADD_INTERVAL 350
#define DATE_SUB_INTERVAL 351
#define DATE_SYM 352
#define DAY_HOUR_SYM 353
#define DAY_MICROSECOND_SYM 354
#define DAY_MINUTE_SYM 355
#define DAY_SECOND_SYM 356
#define DAY_SYM 357
#define DEALLOCATE_SYM 358
#define DECIMAL_NUM 359
#define DECIMAL_SYM 360
#define DECLARE_SYM 361
#define DECODE_SYM 362
#define DEFAULT 363
#define DEFINER_SYM 364
#define DELAYED_SYM 365
#define DELAY_KEY_WRITE_SYM 366
#define DELETE_SYM 367
#define DESC 368
#define DESCRIBE 369
#define DES_DECRYPT_SYM 370
#define DES_ENCRYPT_SYM 371
#define DES_KEY_FILE 372
#define DETERMINISTIC_SYM 373
#define DIRECTORY_SYM 374
#define DISABLE_SYM 375
#define DISCARD 376
#define DISTINCT 377
#define DIV_SYM 378
#define DOUBLE_SYM 379
#define DO_SYM 380
#define DROP 381
#define DUAL_SYM 382
#define DUMPFILE 383
#define DUPLICATE_SYM 384
#define DYNAMIC_SYM 385
#define EACH_SYM 386
#define ELSEIF_SYM 387
#define ELT_FUNC 388
#define ENABLE_SYM 389
#define ENCLOSED 390
#define ENCODE_SYM 391
#define ENCRYPT 392
#define END 393
#define ENGINES_SYM 394
#define ENGINE_SYM 395
#define ENUM 396
#define EQ 397
#define EQUAL_SYM 398
#define ERRORS 399
#define ESCAPED 400
#define ESCAPE_SYM 401
#define EVENTS_SYM 402
#define EXECUTE_SYM 403
#define EXISTS 404
#define EXIT_SYM 405
#define EXPANSION_SYM 406
#define EXPORT_SET 407
#define EXTENDED_SYM 408
#define EXTRACT_SYM 409
#define FALSE_SYM 410
#define FAST_SYM 411
#define FETCH_SYM 412
#define FIELD_FUNC 413
#define FILE_SYM 414
#define FIRST_SYM 415
#define FIXED_SYM 416
#define FLOAT_NUM 417
#define FLOAT_SYM 418
#define FLUSH_SYM 419
#define FORCE_SYM 420
#define FOREIGN 421
#define FORMAT_SYM 422
#define FOR_SYM 423
#define FOUND_SYM 424
#define FRAC_SECOND_SYM 425
#define FROM 426
#define FROM_UNIXTIME 427
#define FULL 428
#define FULLTEXT_SYM 429
#define FUNCTION_SYM 430
#define FUNC_ARG0 431
#define FUNC_ARG1 432
#define FUNC_ARG2 433
#define FUNC_ARG3 434
#define GE 435
#define GEOMCOLLFROMTEXT 436
#define GEOMETRYCOLLECTION 437
#define GEOMETRY_SYM 438
#define GEOMFROMTEXT 439
#define GEOMFROMWKB 440
#define GET_FORMAT 441
#define GLOBAL_SYM 442
#define GRANT 443
#define GRANTS 444
#define GREATEST_SYM 445
#define GROUP 446
#define GROUP_CONCAT_SYM 447
#define GROUP_UNIQUE_USERS 448
#define GT_SYM 449
#define HANDLER_SYM 450
#define HASH_SYM 451
#define HAVING 452
#define HELP_SYM 453
#define HEX_NUM 454
#define HIGH_PRIORITY 455
#define HOSTS_SYM 456
#define HOUR_MICROSECOND_SYM 457
#define HOUR_MINUTE_SYM 458
#define HOUR_SECOND_SYM 459
#define HOUR_SYM 460
#define IDENT 461
#define IDENTIFIED_SYM 462
#define IDENT_QUOTED 463
#define IF 464
#define IGNORE_SYM 465
#define IMPORT 466
#define INDEXES 467
#define INDEX_SYM 468
#define INFILE 469
#define INNER_SYM 470
#define INNOBASE_SYM 471
#define INOUT_SYM 472
#define INSENSITIVE_SYM 473
#define INSERT 474
#define INSERT_METHOD 475
#define INTERVAL_SYM 476
#define INTO 477
#define INT_SYM 478
#define INVOKER_SYM 479
#define IN_SYM 480
#define IS 481
#define ISOLATION 482
#define ISSUER_SYM 483
#define ITERATE_SYM 484
#define JOIN_SYM 485
#define KEYS 486
#define KEY_SYM 487
#define KILL_SYM 488
#define LABEL_SYM 489
#define LANGUAGE_SYM 490
#define LAST_INSERT_ID 491
#define LAST_SYM 492
#define LE 493
#define LEADING 494
#define LEAST_SYM 495
#define LEAVES 496
#define LEAVE_SYM 497
#define LEFT 498
#define LEVEL_SYM 499
#define LEX_HOSTNAME 500
#define LIKE 501
#define LIMIT 502
#define LINEFROMTEXT 503
#define LINES 504
#define LINESTRING 505
#define LOAD 506
#define LOCAL_SYM 507
#define LOCATE 508
#define LOCATOR_SYM 509
#define LOCKS_SYM 510
#define LOCK_SYM 511
#define LOGS_SYM 512
#define LOG_SYM 513
#define LONGBLOB 514
#define LONGTEXT 515
#define LONG_NUM 516
#define LONG_SYM 517
#define LOOP_SYM 518
#define LOW_PRIORITY 519
#define LT 520
#define MAKE_SET_SYM 521
#define MASTER_CONNECT_RETRY_SYM 522
#define MASTER_HOST_SYM 523
#define MASTER_LOG_FILE_SYM 524
#define MASTER_LOG_POS_SYM 525
#define MASTER_PASSWORD_SYM 526
#define MASTER_PORT_SYM 527
#define MASTER_POS_WAIT 528
#define MASTER_SERVER_ID_SYM 529
#define MASTER_SSL_CAPATH_SYM 530
#define MASTER_SSL_CA_SYM 531
#define MASTER_SSL_CERT_SYM 532
#define MASTER_SSL_CIPHER_SYM 533
#define MASTER_SSL_KEY_SYM 534
#define MASTER_SSL_SYM 535
#define MASTER_SYM 536
#define MASTER_USER_SYM 537
#define MATCH 538
#define MAX_CONNECTIONS_PER_HOUR 539
#define MAX_QUERIES_PER_HOUR 540
#define MAX_ROWS 541
#define MAX_SYM 542
#define MAX_UPDATES_PER_HOUR 543
#define MAX_USER_CONNECTIONS_SYM 544
#define MEDIUMBLOB 545
#define MEDIUMINT 546
#define MEDIUMTEXT 547
#define MEDIUM_SYM 548
#define MERGE_SYM 549
#define MICROSECOND_SYM 550
#define MIGRATE_SYM 551
#define MINUTE_MICROSECOND_SYM 552
#define MINUTE_SECOND_SYM 553
#define MINUTE_SYM 554
#define MIN_ROWS 555
#define MIN_SYM 556
#define MLINEFROMTEXT 557
#define MODE_SYM 558
#define MODIFIES_SYM 559
#define MODIFY_SYM 560
#define MOD_SYM 561
#define MONTH_SYM 562
#define MPOINTFROMTEXT 563
#define MPOLYFROMTEXT 564
#define MULTILINESTRING 565
#define MULTIPOINT 566
#define MULTIPOLYGON 567
#define MUTEX_SYM 568
#define NAMES_SYM 569
#define NAME_SYM 570
#define NATIONAL_SYM 571
#define NATURAL 572
#define NCHAR_STRING 573
#define NCHAR_SYM 574
#define NDBCLUSTER_SYM 575
#define NE 576
#define NEW_SYM 577
#define NEXT_SYM 578
#define NONE_SYM 579
#define NOT2_SYM 580
#define NOT_SYM 581
#define NOW_SYM 582
#define NO_SYM 583
#define NO_WRITE_TO_BINLOG 584
#define NULL_SYM 585
#define NUM 586
#define NUMERIC_SYM 587
#define NVARCHAR_SYM 588
#define OFFSET_SYM 589
#define OJ_SYM 590
#define OLD_PASSWORD 591
#define ON 592
#define ONE_SHOT_SYM 593
#define ONE_SYM 594
#define OPEN_SYM 595
#define OPTIMIZE 596
#define OPTION 597
#define OPTIONALLY 598
#define OR2_SYM 599
#define ORDER_SYM 600
#define OR_OR_SYM 601
#define OR_SYM 602
#define OUTER 603
#define OUTFILE 604
#define OUT_SYM 605
#define PACK_KEYS_SYM 606
#define PARTIAL 607
#define PASSWORD 608
#define PARAM_MARKER 609
#define PHASE_SYM 610
#define POINTFROMTEXT 611
#define POINT_SYM 612
#define POLYFROMTEXT 613
#define POLYGON 614
#define POSITION_SYM 615
#define PRECISION 616
#define PREPARE_SYM 617
#define PREV_SYM 618
#define PRIMARY_SYM 619
#define PRIVILEGES 620
#define PROCEDURE 621
#define PROCESS 622
#define PROCESSLIST_SYM 623
#define PURGE 624
#define QUARTER_SYM 625
#define QUERY_SYM 626
#define QUICK 627
#define RAID_0_SYM 628
#define RAID_CHUNKS 629
#define RAID_CHUNKSIZE 630
#define RAID_STRIPED_SYM 631
#define RAID_TYPE 632
#define RAND 633
#define READS_SYM 634
#define READ_SYM 635
#define REAL 636
#define RECOVER_SYM 637
#define REDUNDANT_SYM 638
#define REFERENCES 639
#define REGEXP 640
#define RELAY_LOG_FILE_SYM 641
#define RELAY_LOG_POS_SYM 642
#define RELAY_THREAD 643
#define RELEASE_SYM 644
#define RELOAD 645
#define RENAME 646
#define REPAIR 647
#define REPEATABLE_SYM 648
#define REPEAT_SYM 649
#define REPLACE 650
#define REPLICATION 651
#define REQUIRE_SYM 652
#define RESET_SYM 653
#define RESOURCES 654
#define RESTORE_SYM 655
#define RESTRICT 656
#define RESUME_SYM 657
#define RETURNS_SYM 658
#define RETURN_SYM 659
#define REVOKE 660
#define RIGHT 661
#define ROLLBACK_SYM 662
#define ROLLUP_SYM 663
#define ROUND 664
#define ROUTINE_SYM 665
#define ROWS_SYM 666
#define ROW_COUNT_SYM 667
#define ROW_FORMAT_SYM 668
#define ROW_SYM 669
#define RTREE_SYM 670
#define SAVEPOINT_SYM 671
#define SECOND_MICROSECOND_SYM 672
#define SECOND_SYM 673
#define SECURITY_SYM 674
#define SELECT_SYM 675
#define SENSITIVE_SYM 676
#define SEPARATOR_SYM 677
#define SERIALIZABLE_SYM 678
#define SERIAL_SYM 679
#define SESSION_SYM 680
#define SET 681
#define SET_VAR 682
#define SHARE_SYM 683
#define SHIFT_LEFT 684
#define SHIFT_RIGHT 685
#define SHOW 686
#define SHUTDOWN 687
#define SIGNED_SYM 688
#define SIMPLE_SYM 689
#define SLAVE 690
#define SMALLINT 691
#define SNAPSHOT_SYM 692
#define SOUNDS_SYM 693
#define SPATIAL_SYM 694
#define SPECIFIC_SYM 695
#define SQLEXCEPTION_SYM 696
#define SQLSTATE_SYM 697
#define SQLWARNING_SYM 698
#define SQL_BIG_RESULT 699
#define SQL_BUFFER_RESULT 700
#define SQL_CACHE_SYM 701
#define SQL_CALC_FOUND_ROWS 702
#define SQL_NO_CACHE_SYM 703
#define SQL_SMALL_RESULT 704
#define SQL_SYM 705
#define SQL_THREAD 706
#define SSL_SYM 707
#define STARTING 708
#define START_SYM 709
#define STATUS_SYM 710
#define STD_SYM 711
#define STDDEV_SAMP_SYM 712
#define STOP_SYM 713
#define STORAGE_SYM 714
#define STRAIGHT_JOIN 715
#define STRING_SYM 716
#define SUBDATE_SYM 717
#define SUBJECT_SYM 718
#define SUBSTRING 719
#define SUBSTRING_INDEX 720
#define SUM_SYM 721
#define SUPER_SYM 722
#define SUSPEND_SYM 723
#define SYSDATE 724
#define TABLES 725
#define TABLESPACE 726
#define TABLE_SYM 727
#define TEMPORARY 728
#define TEMPTABLE_SYM 729
#define TERMINATED 730
#define TEXT_STRING 731
#define TEXT_SYM 732
#define TIMESTAMP 733
#define TIMESTAMP_ADD 734
#define TIMESTAMP_DIFF 735
#define TIME_SYM 736
#define TINYBLOB 737
#define TINYINT 738
#define TINYTEXT 739
#define TO_SYM 740
#define TRAILING 741
#define TRANSACTION_SYM 742
#define TRIGGER_SYM 743
#define TRIGGERS_SYM 744
#define TRIM 745
#define TRUE_SYM 746
#define TRUNCATE_SYM 747
#define TYPES_SYM 748
#define TYPE_SYM 749
#define UDF_RETURNS_SYM 750
#define UDF_SONAME_SYM 751
#define ULONGLONG_NUM 752
#define UNCOMMITTED_SYM 753
#define UNDEFINED_SYM 754
#define UNDERSCORE_CHARSET 755
#define UNDO_SYM 756
#define UNICODE_SYM 757
#define UNION_SYM 758
#define UNIQUE_SYM 759
#define UNIQUE_USERS 760
#define UNIX_TIMESTAMP 761
#define UNKNOWN_SYM 762
#define UNLOCK_SYM 763
#define UNSIGNED 764
#define UNTIL_SYM 765
#define UPDATE_SYM 766
#define UPGRADE_SYM 767
#define USAGE 768
#define USER 769
#define USE_FRM 770
#define USE_SYM 771
#define USING 772
#define UTC_DATE_SYM 773
#define UTC_TIMESTAMP_SYM 774
#define UTC_TIME_SYM 775
#define VAR_SAMP_SYM 776
#define VALUES 777
#define VALUE_SYM 778
#define VARBINARY 779
#define VARCHAR 780
#define VARIABLES 781
#define VARIANCE_SYM 782
#define VARYING 783
#define VIEW_SYM 784
#define WARNINGS 785
#define WEEK_SYM 786
#define WHEN_SYM 787
#define WHERE 788
#define WHILE_SYM 789
#define WITH 790
#define WORK_SYM 791
#define WRITE_SYM 792
#define X509_SYM 793
#define XA_SYM 794
#define XOR 795
#define YEARWEEK 796
#define YEAR_MONTH_SYM 797
#define YEAR_SYM 798
#define ZEROFILL 799
#define TABLE_REF_PRIORITY 800
#define ELSE 801
#define THEN_SYM 802
#define CASE_SYM 803
#define BETWEEN_SYM 804
#define NEG 805




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 100 "sql_yacc.yy"
typedef union YYSTYPE {
  int  num;
  ulong ulong_num;
  ulonglong ulonglong_number;
  LEX_STRING lex_str;
  LEX_STRING *lex_str_ptr;
  LEX_SYMBOL symbol;
  Table_ident *table;
  char *simple_string;
  Item *item;
  Item_num *item_num;
  List<Item> *item_list;
  List<String> *string_list;
  String *string;
  key_part_spec *key_part;
  TABLE_LIST *table_list;
  udf_func *udf;
  LEX_USER *lex_user;
  struct sys_var_with_base variable;
  enum enum_var_type var_type;
  Key::Keytype key_type;
  enum ha_key_alg key_alg;
  enum db_type db_type;
  enum row_type row_type;
  enum ha_rkey_function ha_rkey_mode;
  enum enum_tx_isolation tx_isolation;
  enum Cast_target cast_type;
  enum Item_udftype udf_type;
  CHARSET_INFO *charset;
  thr_lock_type lock_type;
  interval_type interval, interval_time_st;
  timestamp_type date_time_type;
  st_select_lex *select_lex;
  chooser_compare_func_creator boolfunc2creator;
  struct sp_cond_type *spcondtype;
  struct { int vars, conds, hndlrs, curs; } spblock;
  sp_name *spname;
  struct st_lex *lex;
} YYSTYPE;
/* Line 1318 of yacc.c.  */
#line 1177 "sql_yacc.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif




