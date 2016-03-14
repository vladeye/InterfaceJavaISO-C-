#ifndef __ID_TRANSACTIONS_H__
#define __ID_TRANSACTIONS_H__

#define _TRANSACTION_VALIDATE_USER  (int)1
#define _TRANSACTION_GET_LIST_RESELLER_COMPANY_NAME (int)2
#define _TRANSACTION_ADD_NEW_RATINGS_AND_REVIEW (int)3
#define _TRANSACTION_GET_COUNTRIES  (int)4
#define _TRANSACTION_GET_USER_SETTINGS (int)5
#define _TRANSACTION_GET_USER_ACTIVITY (int)6
#define _TRANSACTION_GET_CONSUMER_BY_EMAIL_AND_STATUS (int)7
#define _TRANSACTION_GET_INVOICES_BY_DATE   (int)8
#define _TRANSACTION_GET_INVOICES_BY_CONSUMER_ID (int)9
#define _TRANSACTION_GET_PAYABLE_ACCOUNTS (int)10
#define _TRANSACTION_GET_RECEIVABLE_ACCOUNTS (int)11
#define _TRANSACTION_GET_CATEGORY_BY_ID     (int)12
#define _TRANSACTION_GET_STATES_BY_COUNTRY_CODE     (int)13
#define _TRANSACTION_GET_PAYABLE_ACCOUNTS_BY (int)14
#define _TRANSACTION_GET_RECEIVABLE_ACCOUNTS_BY (int)15
#define _TRANSACTION_GET_CATEGORIES (int)16
#define _TRANSACTION_CREATE_CATEGORY (int)17
#define _TRANSACTION_CREATE_SUBCATEGORY (int)18
#define _TRANSACTION_GET_SUBCATEGORIES (int)19
#define _TRANSACTION_REMOVE_CATEGORY (int)20
#define _TRANSACTION_EDIT_CATEGORY (int)21
#define _TRANSACTION_REMOVE_SUBCATEGORY (int)22
#define _TRANSACTION_EDIT_SUBCATEGORY (int)23
#define _TRANSACTION_ADD_ADITIONAL_CATEGORY (int)24
#define _TRANSACTION_EDIT_ADITIONAL_CATEGORY (int)25
#define _TRANSACTION_DELETE_ADITIONAL_CATEGORY (int)26
#define _TRANSACTION_GET_TICKETS_BY_CONSUMER (int)27
#define _TRANSACTION_GET_SECURITY_TICKETS_BY_CONSUMER_ID (int)28
#define _TRANSACTION_GET_MERCHANT_LOYALTY_PROGRAMS (int)29
#define _TRANSACTION_GET_CONSUMER_CLUBS_AND_MEMBERSHIPS (int)30
#define _TRANSACTION_GET_MERCHANT_CLUBS_AND_MEMBERSHIPS (int)31
#define _TRANSACTION_GET_CONSUMER_LOYALTY_PROGRAMS (int)32
#define _TRANSACTION_GET_CUSTOMER_RATINGS (int) 33
#define _TRANSACTION_GET_RESELLER_RATINGS (int) 34
#define _TRANSACTION_GET_RATINGS_BY_USER_ID (int) 35
#define _TRANSACTION_GET_NOTES_BY_USER_ID (int) 36
#define _TRANSACTION_GET_MERCHANT_RATINGS (int) 37
#define _TRANSACTION_GET_SUBCATEGORIES_BY_PARENT_ID     (int)38
#define _TRANSACTION_ADMIN_NEW_CONSUMER     (int)39
#define _TRANSACTION_GET_USERS_MERCHANT (int)40
#define _TRANSACTION_GET_USERS_CONSUMER (int)41
#define _TRANSACTION_GET_USERS_RESELLER (int)42
#define _TRANSACTION_GET_CONSUMER_BY_ID (int)43
#define _TRANSACTION_GET_MERCHANT_BY_ID (int)44
#define _TRANSACTION_GET_RESELLER_BY_ID (int)45
#define _TRANSACTION_ADD_CONSUMER_WISH_LIST (int)46
#define _TRANSACTION_REMOVE_CONSUMER_WISH_LIST (int)47
#define _TRANSACTION_GET_CONSUMER_WISH_LIST (int)48
#define _TRANSACTION_ADD_LOYALTY_PROGRAMS_TO_WISH_LIST (int)49
#define _TRANSACTION_REMOVE_LOYALTY_PROGRAMS_TO_WISH_LIST (int)50
#define _TRANSACTION_GET_CONSUMER_INVOICES (int)51
#define _TRANSACTION_GET_CONSUMER_COUPON_AND_PROMOTIONS (int)52
#define _TRANSACTION_GET_CLUBS_AND_MEMBERSHIPS (int)53
#define _TRANSACTION_ADD_FAVORITE_MERCHANT (int)54
#define _TRANSACTION_REMOVE_FAVORITE_MERCHANT (int)55
#define _TRANSACTION_GET_FAVORITE_MERCHANT (int)56
#define _TRANSACTION_ADD_FAVORITE_CATEGORY (int)57
#define _TRANSACTION_GET_FAVORITE_CATEGORY (int)58
#define _TRANSACTION_REMOVE_FAVORITE_CATEGORY (int)59
#define _TRANSACTION_ADD_FAVORITE_ADDRESS (int)60
#define _TRANSACTION_GET_FAVORITE_ADDRESS (int)61
#define _TRANSACTION_REMOVE_FAVORITE_ADDRESS (int)62
#define _TRANSACTION_LOSTPHONE (int)63
#define _TRANSACTION_SEARCH_USER_CONSUMER (int)64
#define _TRANSACTION_SEARCH_USER_MERCHANT (int)65
#define _TRANSACTION_SEARCH_USER_RESELLER (int)66
#define _TRANSACTION_GET_RATINGS_AND_REVIEWS_BY_PARENT_ID (int)67
#define _TRANSACTION_LOYALTY_PROGRAMS_LIST (int)68
#define _TRANSACTION_LOYALTY_PROGRAMS_FILTER (int)69
#define _TRANSACTION_LOYALTY_ADD_NEW_LOYALTY_PROGRAMS (int)70
#define _TRANSACTION_REMOTE_ITEMS_LIST (int)71
#define _TRANSACTION_REMOTE_ITEMS_FILTER (int)72
#define _TRANSACTION_REMOTE_ITEMS_ADD_NEW_LOYALTY_PROGRAM (int)73
#define _TRANSACTION_HISTORY_LIST (int)74
#define _TRANSACTION_HISTORY_FILTER (int)75
#define _TRANSACTION_RATINGS_AND_REVIEWS_LIST (int)76
#define _TRANSACTION_RATINGS_AND_REVIEWS_FILTER (int)77
#define _TRANSACTION_GET_CATEGORY_BY_PARENT_ID (int)78
#define _TRANSACTION_EDIT_MAIL_CONSUMER (int)79
#define _TRANSACTION_CHANGE_PASSWORD_CONSUMER (int)80
#define _TRANSACTION_USER_MANAGEMENT (int)81
#define _TRANSACTION_PAYMENT_DATA (int)82
#define _TRANSACTION_ADMIN_NEW_MERCHANT     (int)83
#define _TRANSACTION_PROFILE_EDIT_LOCATIONS (int)84
#define _TRANSACTION_PROFILE_ADD_LOCATIONS (int)85
#define _TRANSACTION_DISABLE_LOCATIONS (int)86
#define _TRANSACTION_PROFILE_EDIT_PERMISIONS_CONSUMER (int)87
#define _TRANSACTION_PROFILE_ADD_NEW_CONSUMER (int)88
#define _TRANSACTION_ADMIN_NEW_RESELLER     (int)89
#define _TRANSACTION_PROFILE_REMOVE_USER_CONSUMER (int)90
#define _TRANSACTION_VIEW_BILLING_HISTORY_LIST (int)91
#define _TRANSACTION_EXISTING_SUBSCRIPTIONS (int)92
#define _TRANSACTION_ADD_ONS_FOR_EXISTING_SUBSCRIPTIONS (int)93
#define _TRANSACTION_NEW_SUBSCRIPTIONS (int)94
#define _TRANSACTION_EDIT_MAIL_MERCHANT (int)95
#define _TRANSACTION_EDIT_MAIL_RESELLER (int)96
#define _TRANSACTION_PROFILE_ADD_NEW_MERCHANT (int)97
#define _TRANSACTION_PROFILE_ADD_NEW_RESELLER (int)98
#define _TRANSACTION_PROFILE_EDIT_CONSUMER      (int)99
#define _TRANSACTION_PROFILE_EDIT_MERCHANT      (int)100
#define _TRANSACTION_PROFILE_EDIT_RESELLER      (int)101
#define _TRANSACTION_CHANGE_PASSWORD_MERCHANT (int)102
#define _TRANSACTION_CHANGE_PASSWORD_RESELLER (int)103
#define _TRANSACTION_PROFILE_REMOVE_USER_MERCHANT (int)104
#define _TRANSACTION_PROFILE_REMOVE_USER_RESELLER (int)105
#define _TRANSACTION_PROFILE_EDIT_PERMISIONS_MERCHANT   (int)106
#define _TRANSACTION_PROFILE_EDIT_PERMISIONS_RESELLER   (int)107
#define _TRANSACTION_GET_MERCHANT_BY_EMAIL_AND_STATUS (int)108
#define _TRANSACTION_GET_RESELLER_BY_EMAIL_AND_STATUS (int)109
#define _TRANSACTION_GET_RECENT_INVOICES (int)110
#define _TRANSACTION_REGISTER_MERCHANT  (int)111
#define _TRANSACTION_GET_INVOICES_BY_MERCHANT_ID (int)112
#define _TRANSACTION_GET_INVOICES_BY_RESELLER_ID (int)113
#define _TRANSACTION_GET_SECURITY_TICKETS_BY_MERCHANT_BY_ID (int)114
#define _TRANSACTION_GET_SECURITY_TICKETS_BY_RESELLER_BY_ID (int)115
#define _TRANSACTION_ADD_MERCHANT_ACCOUNT_NAME    (int)116
#define _TRANSACTION_GET_TICKETS_BY_MERCHANT (int)117
#define _TRANSACTION_GET_TICKETS_BY_RESELLER (int)118
#define _TRANSACTION_ADD_STORE_MERCHANT     (int)119
#define _TRANSACTION_VALIDATE_EMAIL (int)120
#define _TRANSACTION_VALIDATE_COMPANNY_NAME (int)121
#define _TRANSACTION_GET_CONSUMER_BY    (int)122
#define _TRANSACTION_GET_MERCHANT_BY    (int)123
#define _TRANSACTION_GET_RESELLER_BY    (int)124
#define _TRANSACTION_ADD_NEW_COUPON     (int)125
#define _TRANSACTION_ADD_NEW_PROMOTION  (int)126
#define _TRANSACTION_REGISTER_CONSUMER  (int)127
#define _TRANSACTION_ADD_NEW_CLUB_AND_MEMBERSHIP  (int)128
#define _TRANSACTION_GET_COUPON (int)129
#define _TRANSACTION_GET_PROMOTION (int)130
#define _TRANSACTION_GET_COUPON_BY_MERCHANT_ID (int)131
#define _TRANSACTION_GET_PROMOTION_BY_MERCHANT_ID (int)132
#define _TRANSACTION_GET_CLUBS_AND_MEMBERSHIPS_BY_MERCHANT_ID (int)133
#define _TRANSACTION_ADD_NEW_LOG (int)134
#define _TRANSACTION_GET_LOGS  (int)135
#define _TRANSACTION_GET_MERCHANT_COUPON_FILTER (int)136
#define _TRANSACTION_GET_MERCHANT_PROMOTION_FILTER (int)137
#define _TRANSACTION_GET_MERCHANT_CLUBS_AND_MEMBERSHIPS_FILTER (int)138
#define _TRANSACTION_GET_CONSUMER_COUPON_FILTER (int)139
#define _TRANSACTION_GET_CONSUMER_PROMOTION_FILTER (int)140
#define _TRANSACTION_GET_CONSUMER_CLUBS_AND_MEMBERSHIPS_FILTER (int)141
#define _TRANSACTION_ADD_LOCATION_TO_LOYALTY_PROGRAM        (int)142
#define _TRANSACTION_REMOVE_LOCATION_TO_LOYALTY_PROGRAM (int)143
#define _TRANSACTION_GET_LOYALTY_PROGRAMS_BY_LOCATION_ID    (int)144
#define _TRANSACTION_ADD_REMOTE_ITEMS_TO_LOYALTY_PROGRAM        (int)145
#define _TRANSACTION_REMOVE_REMOTE_ITEMS_TO_LOYALTY_PROGRAM (int)146
#define _TRANSACTION_GET_REMOTE_ITEMS_BY_LOYALTY_PROGRAM_ID    (int)147
#define _TRANSACTION_ADD_SHOPPING_LIST  (int)148
#define _TRANSACTION_REMOVE_SHOPPING_LIST  (int)149
#define _TRANSACTION_ADD_ITEMS_TO_SHOPPING_LIST (int)150
#define _TRANSACTION_REMOVE_ITEMS_TO_SHOPPING_LIST  (int)151
#define _TRANSACTION_EDIT_SHOPPING_LIST_NAME    (int)152
#define _TRANSACTION_GET_SHOPPING_LIST_BY_CONSUMER_ID (int)153
#define _TRANSACTION_GET_LOYALTY_PROGRAMS_BY_REMOTE_ITEM_ID (int)154
#define _TRANSACTION_GET_NAME_SHOPPING_LIST_BY_CONSUMER_ID (int)155
#define _TRANSACTION_GET_SHOPPING_REMOTE_ITEMS_FILTER    (int)156
#define _TRANSACTION_GET_SHOPPING_LOYALTY_PROGRAMS_FILTER    (int)157
#define _TRANSACTION_GET_REMOTE_ITEMS_BY_MERCHANT_ID (int)158
#define _TRANSACTION_ADD_NEW_REMOTE_ITEM    (int)159
#define _TRANSACTION_GET_SHOPPING_LIST_NAME (int)160
#define _TRANSACTION_GET_CREDIT_CARD_BY_CONSUMER_ID (int)161
#define _TRANSACTION_TOTAL_SALES_PER_DAY (int)162
#define _TRANSACTION_ADD_NEW_SHIPPING_OPTIONS (int)163
#define _TRANSACTION_GET_SHIPPING_OPTION (int)164
#define _TRANSACTION_EDIT_SHIPPING_OPTIONS (int)165
#define _TRANSACTION_REMOVE_SHIPPING_OPTIONS (int)166
#define _TRANSACTION_GET_COUPON_BY_ID (int)167
#define _TRANSACTION_GET_CLUBS_AND_MEMBERSHIPS_BY_ID (int)168
#define _TRANSACTION_GET_PROMOTION_BY_ID (int)169
#define _TRANSACTION_IS_FAVORITE_MERCHANT (int)170
#define _TRANSACTION_GET_INVOICES_CONSUMER_FILTER (int)171
#define _TRANSACTION_MOVE_ITEM_BETWEEN_SHOPPING_LIST (int)172
#define _TRANSACTION_GET_RATINGS_AND_REVIEWS_BY_CONSUMER_ID (int)173
#define _TRANSACTION_GET_CONSUMER_GET_RATINGS_AND_REVIEWS_FILTER (int) 174
#define _TRANSACTION_GET_COUPON_TO_EXPIRE_BY_CONSUMER_ID (int)175
#define _TRANSACTION_GET_ADDRESS_BY_CONSUMER_ID (int)176
#define _TRANSACTION_CHANGE_PASSCODE (int)177
#define _TRANSACTION_EDIT_LANGUAGE_AND_LOCK_TIME (int)178
#define _TRANSACTION_GET_LAST_COUPON_CREATED_BY_MERCHANT_ID (int)179
#define _TRANSACTION_REGISTER_USER_MERCHANT     (int)180
#define _TRANSACTION_GET_RATINGS_AND_REVIEWS_BY_ID (int)181
#define _TRANSACTION_REPLAY_RATINGS_AND_REVIEWS (int)182
#define _TRANSACTION_REPORT_TO_NMC (int)183
#define _TRANSACTION_GET_RECENT_MESSAGE_SYSTEM_BY_MERCHANT_ID (int)184
#define _TRANSACTION_ADD_NEW_HELP_TICKETS (int)185
#define _TRANSACTION_GET_HELP_TICKETS_BY_ID (int)186
#define _TRANSACTION_GET_TICKETS_BY_PARENT_ID (int)187
#define _TRANSACTION_ADD_NEW_ACTION (int)188
#define _TRANSACTION_GET_INVOICES_BY_DATE_AND_MERCHANT_ID (int)189
#define _TRANSACTION_GET_CATEGORY_OF_BUSINESS_LIST (int)190
#define _TRANSACTION_GET_SUBCATEGORY_OF_BUSINESS_BY_PARENT_ID_LIST (int)191
#define _TRANSACTION_VALIDATE_RATING_AND_REVIEW_IS_REPORTED_TO_NMC (int)192
#define _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_LOTALTY    (int)193
#define _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_REMOTE    (int)194
#define _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_ACCOUNTING    (int)195
#define _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_TRANSACTIONS    (int)196
#define _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_SUBSCRIPTIONS    (int)197
#define _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_REVIEWS    (int)198
#define _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_USERS    (int)199
#define _TRANSACTION_GET_PERMISSION_TRANSACTIONS_BY_MERCHANT_ID (int)200
#define _TRANSACTION_GET_PERMISSION_SUBSCRIPTIONS_BY_MERCHANT_ID (int)201
#define _TRANSACTION_GET_PERMISSION_REVIEWS_BY_MERCHANT_ID (int)202
#define _TRANSACTION_GET_PERMISSION_LOYALTY_BY_MERCHANT_ID (int)203
#define _TRANSACTION_GET_PERMISSION_ACCOUNTING_BY_MERCHANT_ID (int)204
#define _TRANSACTION_GET_PERMISSION_REMOTE_BY_MERCHANT_ID (int)205
#define _TRANSACTION_GET_PERMISSION_USER_BY_MERCHANT_ID (int)206
#define _TRANSACTION_GET_IMAGES_BY_LOYALTY_ID (int)207
#define _TRANSACTION_GET_LOYALTY_PROGRAMS_BY_USER_MERCHANT (int)208
#define _TRANSACTION_GET_CATEGORY_BY_TYPE (int)209
#define _TRANSACTION_GET_TYPES_OF_CATEGORIES (int)210
#define _TRANSACTION_GET_LOCATIONS_BY_MERCHANT_ID (int)211
#define _TRANSACTION_ADD_IMAGES_TO_LOYALTY_PROGRAMS (int)212
#define _TRANSACTION_ADD_LOCATIONS_TO_LOYALTY_PROGRAMS (int)213
#define _TRANSACTION_GET_COUNTRY_CURRENCY_CODE (int)214
#define _TRANSACTION_ADD_IMAGES_TO_REMOTE_ITEMS (int)215
#define _TRANSACTION_GET_COMPANY_NAME_BY_MERCHANT_ID (int)216
#define _TRANSACTION_ADD_NEW_CATALOG (int)217
#define _TRANSACTION_GET_CHOICES_BY_OPTION_ID (int)218
#define _TRANSACTION_GET_OPTIONS_BY_REMOTE_ID (int)219
#define _TRANSACTION_GET_TOTAL_BY_OPTION_ID (int)220
#define _TRANSACTION_ADD_NEW_CHOICE (int)221
#define _TRANSACTION_ADD_NEW_OPTION (int)222
#define _TRANSACTION_ADD_TOTAL_BY_OPTION_ID (int)223
#define _TRANSACTION_GET_CATALOGS_BY_MERCHANT_ID (int)224
#define _TRANSACTION_GET_CITIES_BY_STATE_ID (int)225
#define _TRANSACTION_REMOVE_CATALOG (int) 226
#define _TRANSACTION_MOVE_TO_CATALOG (int) 227
#define _TRANSACTION_REMOVE_ITEMS_FROM_CATALOG (int) 228
#define _TRANSACTION_GET_REMOTE_ITEMS_BY_CATALOG_ID (int)229
#define _TRANSACTION_GET_MESSAGE_BY_INVOICE_ID (int)230
#define _TRANSACTION_GET_MESSAGE_BY_MERCHANT_ID (int)231
#define _TRANSACTION_GET_TRANSACTIONS_BY_MERCHANT_ID (int)232
#define _TRANSACTION_ADD_NEW_INVOICE_MESSAGE  (int)233
#define _TRANSACTION_ADD_NEW_INVOICE_NOTE  (int)234
#define _TRANSACTION_GET_SEQ_IMAGES_NAME (int) 235
#define _TRANSACTION_GET_INVOICE_DETAILS_CATALOG_BY_MERCHANT_ID (int)236
#define _TRANSACTION_GET_INVOICE_DETAILS_LOYALTY_BY_MERCHANT_ID (int)237
#define _TRANSACTION_GET_INVOICE_DETAILS_REMOTE_ITEMS_BY_MERCHANT_ID (int)238
#define _TRANSACTION_GET_NOTES_BY_INVOICE_ID  (int)239
#define _TRANSACTION_UPDATE_SHIPPING_STATUS_TRANSACTION  (int)240
#define _TRANSACTION_GET_TERMINALS_BY_LOCATION_ID  (int)241
#define _TRANSACTION_PROFILE_GET_MERCHANT_BY_ID  (int)242
#define _TRANSACTION_ADD_NEW_TERMINAL  (int)243
#define _TRANSACTION_DELETE_CREDIT_CARD_MERCHANT  (int)244
#define _TRANSACTION_REMOVE_TERMINALS  (int)245
#define _TRANSACTION_ENABLE_LOCATIONS (int)246
#define _TRANSACTION_GET_CREDIT_CARD_BY_MERCHANT_ID  (int)247
#define _TRANSACTION_GET_BILLING_HISTORY_MERCHANT_BY_MERCHANT_ID  (int)248
#define _TRANSACTION_GET_INACTIVE_LOCATIONS_BY_MERCHANT_ID  (int)249
#define _TRANSACTION_SET_FAVORITE_CREDIT_CARD_MERCHANT  (int)250
#define _TRANSACTION_GET_PAYMENT_METHOD_BY_MERCHANT_ID (int)251
#define _TRANSACTION_GET_TYPE_OF_BUSINESS_BY_MERCHANT_ID (int)252
#define _TRANSACTION_PROFILE_ADD_PAYMENT_METHOD (int)253
#define _TRANSACTION_PROFILE_REMOVE_PAYMENT_METHOD (int)254
#define _TRANSACTION_PROFILE_EDIT_USER_MERCHANT (int)255
#define _TRANSACTION_GET_USERS_MERCHANT_BY_PARENT_ID (int)256
#define _TRANSACTION_ADD_NEW_CONTACT_US_MERCHANT  (int)257
#define _TRANSACTION_GET_HELP_TICKETS_BY_MERCHANT_ID (int)258
#define _TRANSACTION_SUSPEND_USERS_MERCHANT  (int)259
#define _TRANSACTION_DELETE_LOYALTY_PROGRAM_BY_ID  (int)260
#define _TRANSACTION_DELETE_REMOTE_ITEM_BY_ID  (int)261
#define _TRANSACTION_EDIT_LOYALTY_PROGRAMS_BY_ID (int)262
#define _TRANSACTION_EDIT_REMOTE_ITEM_BY_ID (int)263
#define _TRANSACTION_GET_BILLING_HISTORY_LIST_MERCHANT_BY_MERCHANT_ID_FILTER  (int)264
#define _TRANSACTION_GET_HELP_TICKETS_BY_MERCHANT_ID_FILTER  (int)265
#define _TRANSACTION_SEARCH_HELP_TICKETS_BY_MERCHANT_ID  (int)266
#define _TRANSACTION_SEARCH_LOYALTY_PROGRAMS_BY_MERCHANT_ID (int)267
#define _TRANSACTION_EDIT_MERCHANT_PERMISSION_ACCOUNTING (int)268
#define _TRANSACTION_EDIT_MERCHANT_PERMISSION_LOYALTY (int)269
#define _TRANSACTION_EDIT_MERCHANT_PERMISSION_REMOTE (int)270
#define _TRANSACTION_EDIT_MERCHANT_PERMISSION_REVIEWS (int)271
#define _TRANSACTION_EDIT_MERCHANT_PERMISSION_SUBSCRIPTIONS (int)272
#define _TRANSACTION_EDIT_MERCHANT_PERMISSION_TRANSACTIONS (int)273
#define _TRANSACTION_EDIT_MERCHANT_PERMISSION_USERS (int)274
#define _TRANSACTION_GET_CATALOG_LOYALTY_REMOTE_BY_MERCHANT_ID_FOR_ADD  (int)275
#define _TRANSACTION_GET_REMOTE_ITEMS_BY_MERCHANT_ID_FILTER  (int)276
#define _TRANSACTION_SEARCH_REMOTE_ITEMS_BY_CATALOG_ID  (int)277
#define _TRANSACTION_SEARCH_REMOTE_ITEMS_BY_MERCHANT_ID  (int)278
#define _TRANSACTION_GET_REMOTE_ITEMS_BY_CATALOG_ID_FILTER  (int)279
#define _TRANSACTION_SEARCH_USERS_MERCHANT_BY_PARENT_ID  (int)280
#define _TRANSACTION_GET_USERS_MERCHANT_BY_PARENT_ID_FILTER  (int)281
#define _TRANSACTION_SEARCH_MERCHANT_RATINGS  (int)282
#define _TRANSACTION_GET_MERCHANT_RATINGS_FILTER  (int)283
#define _TRANSACTION_ACCEPT_NEW_TRANSACTION  (int)284
#define _TRANSACTION_ADD_NEW_PRODUCT_TRANSACTION  (int)285
#define _TRANSACTION_ADD_NEW_TEMPORAL_TRANSACTION (int)286
#define _TRANSACTION_ADD_REFUND_BY_TRANSACTION_PRODUCT_ID  (int)287
#define _TRANSACTION_GET_TRANSACTIONS_BY_MERCHANT_ID_FILTER  (int)288
#define _TRANSACTION_SEARCH_TRANSACTIONS_BY_MERCHANT_ID  (int)289
#define _TRANSACTION_CONFIRM_MERCHANT_PASSWORD (int)290
#define _TRANSACTION_GET_TRANSACTION_BY_ID (int)291
#define _TRANSACTION_GET_HELP_TICKETS_BY_CONSUMER_ID (int)292
#define _TRANSACTION_GET_RECENT_INVOICES_BY_CONSUMER_ID (int)293
#define _TRANSACTION_SEARCH_INVOICES_BY_CONSUMER_ID (int)294
#define _TRANSACTION_EDIT_TERMINAL (int)295
#define _TRANSACTION_GET_TRANSACTIONS_BY_CARD_TOCKEN (int)296
#define _TRANSACTION_SEARCH_TRANSACTIONS_BY_CARD_TOCKEN (int)297
#define _TRANSACTION_GET_TRANSACTIONS_BY_CARD_TOCKEN_FILTER (int)298
#define _TRANSACTION_ADD_NEW_CREDIT_CARD_MERCHANT (int)299
#define _TRANSACTION_COUNTER_ACCOUNTS_BY_CONSUMER_ID (int)300
#define _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID (int)301
#define _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID_FILTER (int)302
#define _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_BY_SHOPPING_LIST_ID (int)303
#define _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_IN_SHOPPING_LIST_BY_CONSUMER_ID (int)304
#define _TRANSACTION_GET_CONSUMER_COUPON_FILTER_BY_SHOPPING_LIST_ID (int)305
#define _TRANSACTION_GET_CONSUMER_COUPON (int)306
#define _TRANSACTION_GET_STATUS_FACEBOOK_TWITTER_BY_CONSUMER_ID (int)307
#define _TRANSACTION_GET_CONSUMER_PROMOTION_FILTER_BY_SHOPPING_LIST_ID (int)308
#define _TRANSACTION_GET_CONSUMER_PROMOTIONS (int)309
#define _TRANSACTION_GET_CONSUMER_REMOTE_ITEM (int)310
#define _TRANSACTION_GET_COUPON_BY_SHOPPING_LIST_ID (int)311
#define _TRANSACTION_GET_EXPIRING_IN_SEVEN_DAYS_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID (int)312
#define _TRANSACTION_GET_JOINED_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID (int)313
#define _TRANSACTION_GET_JOIN_NOW_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID (int)314
#define _TRANSACTION_GET_PROMOTIONS_BY_SHOPPING_LIST_ID (int)315
#define _TRANSACTION_GET_REMOTE_ITEM_BY_SHOPPING_LIST_ID (int)316
#define _TRANSACTION_SEARCH_CONSUMER_COUPON_AND_PROMOTION (int)317
#define _TRANSACTION_SEARCH_CONSUMER_COUPON_AND_PROMOTION_BY_SHOPPING_LIST_ID (int)318
#define _TRANSACTION_SEARCH_GET_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID (int)319
#define _TRANSACTION_SEARCH_REMOTE_ITEM_BY_SHOPPING_LIST_ID (int)320
#define _TRANSACTION_GET_CONSUMER_CLUB_AND_MEMBERSHIP_FILTER_BY_SHOPPING_LIST_ID (int)321
#define _TRANSACTION_SAVE_SECRET_QUESTION_BY_CONSUMER_ID (int)322
#define _TRANSACTION_ADD_PAYMENT_ACCOUNT_CONSUMER (int)323
#define _TRANSACTION_EDIT_PAYMENT_ACCOUNT_CONSUMER_BY_ID (int)324
#define _TRANSACTION_ADD_IMAGES_TO_PRODUCT_BY_CONSUMER (int)325
#define _TRANSACTION_VALIDATE_CONSUMER_PASSWORD (int)326
#define _TRANSACTION_VALIDATE_CONSUMER_PINCODE (int)327
#define _TRANSACTION_REMOVE_PAYMENT_ACCOUNT_CONSUMER_BY_ID (int)328
#define _TRANSACTION_GET_SALE_ITEMS_BY_CONSUMER_ID (int)329
#define _TRANSACTION_SEARCH_SALE_ITEMS_BY_CONSUMER_ID (int)330
#define _TRANSACTION_GET_SALE_ITEMS_BY_CONSUMER_ID_FILTER (int)331
#define _TRANSACTION_ADD_NEW_CONSUMER_ADDRESS (int)332
#define _TRANSACTION_SET_DEFAULT_CONSUMER_ADDRESS (int)333
#define _TRANSACTION_EDIT_CONSUMER_ADDRESS (int)334
#define _TRANSACTION_REMOVE_CONSUMER_ADDRESS_BY_ID (int)335
#define _TRANSACTION_GET_CONSUMER_ADDRESS_BY_CONSUMER_ID (int)336
#define _TRANSACTION_ADD_NEW_OPTION_CONSUMER (int)337
#define _TRANSACTION_ADD_TOTAL_BY_OPTION_ID_CONSUMER (int)338
#define _TRANSACTION_SET_STATUS_FACEBOOK_TWITTER_BY_CONSUMER_ID (int)339
#define _TRANSACTION_GET_LANGUAGE_SCREEN_LOCK_TIME_BY_CONSUMER_ID (int)340
#define _TRANSACTION_SET_LANGUAGE_SCREEN_LOCK_TIME_BY_CONSUMER_ID (int)341
#define _TRANSACTION_CHANGE_MAIL_CONSUMER (int)342
#define _TRANSACTION_CONTACT_NMC_CONSUMER (int)343
#define _TRANSACTION_ADD_NEW_SALE_ITEM (int)344
#define _TRANSACTION_EDIT_SALE_ITEM (int)345
#define _TRANSACTION_REMOVE_SALE_ITEM (int)346
#define _TRANSACTION_SAVE_STATUS_LOST_PHONE (int)347
#define _TRANSACTION_GET_CONSUMER_NOTIFICATIONS_SETTINGS (int)348
#define _TRANSACTION_EDIT_CONSUMER_NOTIFICATIONS_SETTINGS (int)349
#define _TRANSACTION_DELETE_USER_MERCHANT (int)350
#define _TRANSACTION_EDIT_CREDIT_CARD_MERCHANT (int)351
#define _TRANSACTION_CONTACT_NMC_RESELLER (int)352
#define _TRANSACTION_GET_RESELLER_RATINGS_AND_REVIEWS (int)353
#define _TRANSACTION_SEARCH_RESELLER_RATINGS_AND_REVIEWS (int)354
#define _TRANSACTION_GET_RESELLER_RATINGS_FILTER (int)355
#define _TRANSACTION_GET_RESELLER_HELP_TICKETS_FROM_MERCHANT (int)356
#define _TRANSACTION_GET_RESELLER_HELP_TICKETS_FROM_MERCHANT_FILTER (int)357
#define _TRANSACTION_GET_RESELLER_HELP_TICKETS_TO_ADMIN (int)358
#define _TRANSACTION_GET_RESELLER_HELP_TICKETS_TO_ADMIN_FILTER (int)359
#define _TRANSACTION_SEARCH_RESELLER_HELP_TICKETS_FROM_MERCHANT (int)360
#define _TRANSACTION_SEARCH_RESELLER_HELP_TICKETS_TO_ADMIN (int)361
#define _TRANSACTION_ADD_NEW_HELP_TICKETS_RESELLER (int)362
#define _TRANSACTION_GET_RESELLERS (int)363
#define _TRANSACTION_GET_IMAGES_BY_REMOTE_ITEM_ID (int)364
#define _TRANSACTION_EDIT_MANAGEMENT_USER_MERCHANT (int)365
#define _TRANSACTION_GET_SUPERVISOR_MERCHANT_BY_PARENT_ID (int)366
#define _TRANSACTION_GET_PATH_BY_NAME (int)367
#define _TRANSACTION_EDIT_PATH (int)368
#define _TRANSACTION_ADD_NEW_PATH (int)369
#define _TRANSACTION_VALIDATE_NAME_PATH (int)370
#define _TRANSACTION_GET_TERMINAL_BY_ID (int)371
#define _TRANSACTION_GET_ZIP_CODE_BY_CITY (int)372
#define _TRANSACTION_REGISTER_TEMPORAL_USER (int)373
#define _TRANSACTION_ADD_NEW_PIN_CODE (int)374
#define _TRANSACTION_FORGOT_PASSWORD_CONSUMER (int)375
#define _TRANSACTION_GET_TEMPORAL_USER (int)376
#define _TRANSACTION_REGISTER_USER (int)377
#define _TRANSACTION_VALIDATE_TEMPORAL_EMAIL (int)378
#define _TRANSACTION_VALIDATE_TEMPORAL_USER (int)379
#define _TRANSACTION_CONFIRM_PAYMENT_METHOD_CONSUMER (int)380
#define _TRANSACTION_GET_SECURITY_QUESTIONS (int)381
#define _TRANSACTION_GET_SECURITY_QUESTIONS_BY_ID (int)382
#define _TRANSACTION_VALIDATE_ANSWERS_BY_CONSUMER_ID (int)383
#define _TRANSACTION_GET_RANDOM_SECURITY_QUESTIONS_BY_CONSUMER_ID (int)384


//
#define _TRANSACTION_GET_REMOTE_ITEMS_TO_RECOMMEND_BY_MERCHANT_ID (int)385
#define _TRANSACTION_EDIT_RECOMMENDED_ITEMS (int)386
#define _TRANSACTION_ADD_LOCATIONS_TO_REMOTE_ITEMS  (int)387
#define _TRANSACTION_GET_REMOTE_ITEMS_BY_ID  (int)388
#define _TRANSACTION_GET_BARCODE_LIST  (int)389
#define _TRANSACTION_REMOVE_LOYALTY_PROGRAM  (int)390
#define _TRANSACTION_REMOVE_REMOTE_ITEM  (int)391
#define _TRANSACTION_GET_LOCATIONS_BY_COUPON_ID  (int)392
#define _TRANSACTION_REGISTER_MERCHANT_THREE  (int)393

#define _TRANSACTION_GET_INVOICES_CONSUMER_BY_TRANSACTION_ID  (int)394
#define _TRANSACTION_GET_MESSAGE_COUNT_BY_INVOICE_ID  (int)395
#define _TRANSACTION_GET_CONSUMER_BY_PINCODE  (int)396
#define _TRANSACTION_GET_FIRST_USER  (int)397

#define _TRANSACTION_EDIT_TEMPORAL_PASSWORD_BY_CONSUMER_ID (int)398
#define _TRANSACTION_GET_MESSAGE_BY_CONSUMER_ID  (int)399
#define _TRANSACTION_FORGOT_PASSWORD_MERCHANT  (int)400
#define _TRANSACTION_EDIT_TEMPORAL_PASSWORD_BY_MERCHANT_ID (int)401
#define _TRANSACTION_ADD_SHIPPING_STATUS_TO_TRANSACTION (int)402
#define _TRANSACTION_GET_INVOICE_DETAILS_BY_CONSUMER_ID (int)403

#define _TRANSACTION_GET_CONSUMER_REMOTE_BY_FAVORITE_CATEGORY (int)404
#define _TRANSACTION_GET_CONSUMER_FAVORITE_REMOTE (int)405
#define _TRANSACTION_ADD_FAVORITE_REMOTE (int)406
#define _TRANSACTION_REMOVE_FAVORITE_REMOTE (int)407
#define _TRANSACTION_GET_CONSUMER_COUPONS_BY_FAVORITE_CATEGORY (int)408
#define _TRANSACTION_ADD_FAVORITE_CATALOG (int)409
#define _TRANSACTION_REMOVE_FAVORITE_CATALOG (int)410
#define _TRANSACTION_GET_FAVORITE_CATALOG (int)411
#define _TRANSACTION_GET_REMOTE_ITEMS_BY_CATALOG_ID_PORTAL (int)412
#define _TRANSACTION_ADD_FAVORITE_COUPON (int)413
#define _TRANSACTION_REMOVE_FAVORITE_COUPON (int)414
#define _TRANSACTION_GET_CONSUMER_FAVORITE_CLUB (int)415
#define _TRANSACTION_GET_CONSUMER_FAVORITE_COUPONS (int)416
#define _TRANSACTION_REMOVE_SELECT_COUPON (int)417
#define _TRANSACTION_REMOVE_SELECT_REMOTE (int)418

#define _TRANSACTION_ADD_NEW_INVOICE_MESSAGE_CONSUMER (int)419




#endif
