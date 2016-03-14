#include "InterfaceJavaISO.h"
#include "CoreTransaction.h"
#include "Transactions.h"
#include "IDTransactions.h"
#include "IsoParser.h"
#include "CodeFieldsTransaction.h"
#include "NMCLog.h"
#include "tools.h"

//logs
//#define logbegin	cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- Begin"<<endl
//#define logend      cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- End"<<endl
//#define heavylog	cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- "
//#define logbasic	cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- "
//#define __DEBUG_DATA_2_SEND

#if defined(logbegin) || defined (logend) || defined (logbasic) || defined (__DEBUG_DATA_2_SEND) || defined (heavylog)
    #include <iostream>
    #define _BYTES_PER_LINE 10
#endif




void *ChooseTransactionClass(int nTransaction)
{
    switch(nTransaction)
    {
        case _TRANSACTION_VALIDATE_USER:
            return new ProcessValidateUserTransaction;

        case _TRANSACTION_GET_USER_SETTINGS:
            return new ProcessGetUserSettingsTransaction;

        case _TRANSACTION_GET_USER_ACTIVITY:
            return new ProcessGetUserActivityTransaction;

        case _TRANSACTION_GET_CONSUMER_BY_EMAIL_AND_STATUS:
            return new ProcessGetConsumerByEmailAndStatusTransaction;

        case _TRANSACTION_GET_INVOICES_BY_CONSUMER_ID:
            return new ProcessGetInvoicesByConsumerIdTransaction;



        case _TRANSACTION_GET_PAYABLE_ACCOUNTS:
            return new ProcessGetPayableAccountsTransaction;

        case _TRANSACTION_GET_RECEIVABLE_ACCOUNTS:
            return new ProcessGetReceivableAccountsTransaction;


        case _TRANSACTION_GET_PAYABLE_ACCOUNTS_BY:
            return new ProcessGetPayableAccountsByTransaction;

        case _TRANSACTION_GET_RECEIVABLE_ACCOUNTS_BY:
           return new ProcessGetReceivableAccountsByTransaction;



        case _TRANSACTION_GET_CATEGORIES:
           return new ProcessGetCategoriesTransaction;

        case _TRANSACTION_GET_SUBCATEGORIES:
           return new ProcessGetSubcategoriesTransaction;

        case _TRANSACTION_CREATE_CATEGORY:
           return new ProcessCreateCategoryTransaction;

        case _TRANSACTION_CREATE_SUBCATEGORY:
           return new ProcessCreateSubcategoryTransaction;

        case _TRANSACTION_REMOVE_CATEGORY:
           return new ProcessRemoveCategoryTransaction;

        case _TRANSACTION_EDIT_CATEGORY:
           return new ProcessEditCategoryTransaction;

        case _TRANSACTION_REMOVE_SUBCATEGORY:
           return new ProcessRemoveSubcategoryTransaction;

        case _TRANSACTION_EDIT_SUBCATEGORY:
           return new ProcessEditSubcategoryTransaction;

        case _TRANSACTION_ADD_ADITIONAL_CATEGORY:
           return new ProcessAddAditionalCategoryTransaction;

        case _TRANSACTION_EDIT_ADITIONAL_CATEGORY:
           return new ProcessEditAditionalCategoryTransaction;

        case _TRANSACTION_DELETE_ADITIONAL_CATEGORY:
           return new ProcessDeleteAditionalCategoryTransaction;



        case _TRANSACTION_GET_TICKETS_BY_CONSUMER:
            return new ProcessGetTicketsByConsumerTransaction;

        case _TRANSACTION_GET_SECURITY_TICKETS_BY_CONSUMER_ID:
           return new ProcessGetSecurityTicketsByConsumerIdTransaction;



        case _TRANSACTION_GET_MERCHANT_LOYALTY_PROGRAMS:
             return new ProcessGetMerchantLoyaltyProgramsTransaction;

        case _TRANSACTION_GET_CONSUMER_CLUBS_AND_MEMBERSHIPS:
            return new ProcessGetConsumerClubsAndMembershipsTransaction;

        case _TRANSACTION_GET_MERCHANT_CLUBS_AND_MEMBERSHIPS:
            return new ProcessGetMerchantClubsAndMembershipsTransaction;

        case _TRANSACTION_GET_CONSUMER_LOYALTY_PROGRAMS:
             return new ProcessGetConsumerLoyaltyProgramsTransaction;



        case _TRANSACTION_GET_CUSTOMER_RATINGS:
            return new ProcessGetCustomerRatingsTransaction;

        case _TRANSACTION_GET_RESELLER_RATINGS:
             return new ProcessGetResellerRatingsTransaction;

        case _TRANSACTION_GET_RATINGS_BY_USER_ID:
             return new ProcessGetRatingsByUserIdTransaction;

        case _TRANSACTION_GET_NOTES_BY_USER_ID:
             return new ProcessGetNotesByUserIdTransaction;

        case _TRANSACTION_GET_MERCHANT_RATINGS:
             return new ProcessGetMerchantRatingsTransaction;



        case _TRANSACTION_GET_USERS_MERCHANT:
            return new ProcessGetUsersMerchantTransaction;

        case _TRANSACTION_GET_USERS_CONSUMER:
            return new ProcessGetUsersConsumerTransaction;

        case _TRANSACTION_GET_USERS_RESELLER:
            return new ProcessGetUsersResellerTransaction;

        case _TRANSACTION_GET_CONSUMER_BY_ID:
            return new ProcessGetConsumerByIDTransaction;

        case _TRANSACTION_GET_MERCHANT_BY_ID:
            return new ProcessGetMerchantByIDTransaction;

        case _TRANSACTION_GET_RESELLER_BY_ID:
            return new ProcessGetResellerByIDTransaction;


        case _TRANSACTION_ADD_CONSUMER_WISH_LIST:
             return new ProcessAddConsumerWishListTransaction;

            case _TRANSACTION_REMOVE_CONSUMER_WISH_LIST :
             return new ProcessRemoveConsumerWishListTransaction;

            case _TRANSACTION_GET_CONSUMER_WISH_LIST :
                return new ProcessGetConsumerWishListTransaction;

            case _TRANSACTION_ADD_LOYALTY_PROGRAMS_TO_WISH_LIST :
                return new ProcessAddLoyaltyProgramsToWishListTransaction;

            case _TRANSACTION_REMOVE_LOYALTY_PROGRAMS_TO_WISH_LIST :
                return new ProcessRemoveLoyaltyProgramsToWishListTransaction;

            case _TRANSACTION_GET_CONSUMER_INVOICES :
                return new ProcessGetConsumerInvoicesTransaction;

            case _TRANSACTION_GET_CONSUMER_COUPON_AND_PROMOTIONS :
                return new ProcessGetConsumerCouponAndPromotionsTransaction;

            case _TRANSACTION_GET_CLUBS_AND_MEMBERSHIPS :
                return new ProcessGetClubsAndMembershipsTransaction;

            case _TRANSACTION_ADD_FAVORITE_MERCHANT :
                return new ProcessAddFavoriteMerchantTransaction;

            case _TRANSACTION_REMOVE_FAVORITE_MERCHANT :
                return new ProcessRemoveFavoriteMerchantTransaction;

            case _TRANSACTION_GET_FAVORITE_MERCHANT :
                return new ProcessGetFavoriteMerchantTransaction;

            case _TRANSACTION_ADD_FAVORITE_CATEGORY :
                return new ProcessAddFavoriteCategoryTransaction;

            case _TRANSACTION_GET_FAVORITE_CATEGORY :
                return new ProcessGetFavoriteCategoryTransaction;

            case _TRANSACTION_REMOVE_FAVORITE_CATEGORY :
                return new ProcessRemoveFavoriteCategoryTransaction;

            case _TRANSACTION_ADD_FAVORITE_ADDRESS :
                return new ProcessAddFavoriteAddressTransaction;

            case _TRANSACTION_GET_FAVORITE_ADDRESS :
                return new ProcessGetFavoriteAddressTransaction;

            case _TRANSACTION_REMOVE_FAVORITE_ADDRESS :
                return new ProcessRemoveFavoriteAddressTransaction;

            case _TRANSACTION_LOSTPHONE :
                return new ProcessLostPhoneTransaction;

            case _TRANSACTION_LOYALTY_PROGRAMS_LIST :
               return new ProcessLoyaltyProgramsListTransaction;

            case _TRANSACTION_LOYALTY_PROGRAMS_FILTER :
               return new ProcessLoyaltyProgramsFilterTransaction;

            case _TRANSACTION_LOYALTY_ADD_NEW_LOYALTY_PROGRAMS :
               return new ProcessLoyaltyAddNewLoyalityProgramsTransaction;

            case _TRANSACTION_REMOTE_ITEMS_LIST :
               return new ProcessRemoteItemsListTransaction;

            case _TRANSACTION_REMOTE_ITEMS_FILTER :
               return new ProcessRemoteItemsFilterTransaction;

            case _TRANSACTION_REMOTE_ITEMS_ADD_NEW_LOYALTY_PROGRAM :
               return new ProcessRemoteItemsAddNewLoyaltyProgramTransaction;

            case _TRANSACTION_HISTORY_LIST :
               return new ProcessHistoryListTransaction;

            case _TRANSACTION_HISTORY_FILTER :
               return new ProcessHistoryFilterTransaction;

            case _TRANSACTION_RATINGS_AND_REVIEWS_LIST :
               return new ProcessRatingsAndReviewsListTransaction;

            case _TRANSACTION_RATINGS_AND_REVIEWS_FILTER :
               return new ProcessRatingsAndReviewsFilterTransaction;

            case _TRANSACTION_ADD_NEW_RATINGS_AND_REVIEW:
                return new ProcessAddNewRatingsAndReviewsTransaction;

            case _TRANSACTION_EDIT_MAIL_CONSUMER :
               return new ProcessEditMailConsumerTransaction;

            case _TRANSACTION_CHANGE_PASSWORD_CONSUMER :
               return new ProcessChangePaswordConsumerTransaction;

            case _TRANSACTION_CHANGE_PASSWORD_MERCHANT :
               return new ProcessChangePaswordMerchantTransaction;

            case _TRANSACTION_CHANGE_PASSWORD_RESELLER :
               return new ProcessChangePaswordResellerTransaction;

            case _TRANSACTION_USER_MANAGEMENT :
               return new ProcessUserManagementTransaction;

            case _TRANSACTION_PAYMENT_DATA :
               return new ProcessPaymentDataTransaction;


            case _TRANSACTION_PROFILE_EDIT_LOCATIONS :
               return new ProcessProfileEditLocationsTransaction;

            case _TRANSACTION_PROFILE_ADD_LOCATIONS :
               return new ProcessProfileAddLocationsTransaction;

            case _TRANSACTION_DISABLE_LOCATIONS :
               return new ProcessDisableLocationsTransaction;

            case _TRANSACTION_PROFILE_EDIT_PERMISIONS_CONSUMER :
               return new ProcessProfileEditPermisionsConsumerTransaction;

            case _TRANSACTION_PROFILE_EDIT_PERMISIONS_MERCHANT:
                return new ProcessProfileEditPermisionsMerchantTransaction;

            case _TRANSACTION_PROFILE_EDIT_PERMISIONS_RESELLER:
                return new ProcessProfileEditPermisionsResellerTransaction;

            case _TRANSACTION_PROFILE_ADD_NEW_CONSUMER :
               return new ProcessProfileAddNewConsumerTransaction;


            case _TRANSACTION_PROFILE_REMOVE_USER_CONSUMER :
               return new ProcessProfileRemoveUserConsumerTransaction;

            case _TRANSACTION_PROFILE_REMOVE_USER_MERCHANT:
                return new ProcessProfileRemoveUserMerchantTransaction;

            case _TRANSACTION_PROFILE_REMOVE_USER_RESELLER:
                return new ProcessProfileRemoveUserResellerTransaction;

            case _TRANSACTION_VIEW_BILLING_HISTORY_LIST :
               return new ProcessViewBillingHistyoryListTransaction;

            case _TRANSACTION_EXISTING_SUBSCRIPTIONS :
               return new ProcessExistingSubscriptionsTransaction;

            case _TRANSACTION_ADD_ONS_FOR_EXISTING_SUBSCRIPTIONS :
               return new ProcessAddOnsForExistingSubscriptionsTransaction;

            case _TRANSACTION_NEW_SUBSCRIPTIONS :
               return new ProcessNewSubsicriptionsTransaction;

            case _TRANSACTION_EDIT_MAIL_MERCHANT:
                return new ProcessEditMailMerchantTransaction;

            case _TRANSACTION_EDIT_MAIL_RESELLER:
                return new ProcessEditMailResellerTransaction;

            case _TRANSACTION_PROFILE_ADD_NEW_MERCHANT:
                return new ProcessProfileAddNewMerchantTransaction;

            case _TRANSACTION_PROFILE_ADD_NEW_RESELLER:
                return new ProcessProfileAddNewResellerTransaction;

            case _TRANSACTION_PROFILE_EDIT_CONSUMER:
                return new ProcessProfileEditConsumerTransaction;

            case _TRANSACTION_PROFILE_EDIT_MERCHANT:
                return new ProcessProfileEditMerchantTransaction;

            case _TRANSACTION_PROFILE_EDIT_RESELLER:
                return new ProcessProfileEditResellerTransaction;

            case _TRANSACTION_VALIDATE_EMAIL:
                return new ProcessValidateEmailTransaction;

            case _TRANSACTION_VALIDATE_COMPANNY_NAME:
                return new ProcessValidateCompannyNameTransaction;

            case _TRANSACTION_GET_MERCHANT_BY_EMAIL_AND_STATUS:
                return new ProcessGetMerchantByEmailAndStatusTransaction;

            case _TRANSACTION_GET_RECENT_INVOICES :
                return new ProcessGetRecentInvoicesTransaction;

            case _TRANSACTION_GET_RESELLER_BY_EMAIL_AND_STATUS:
                return new ProcessGetResellerByEmailAndStatusTransaction;

            case _TRANSACTION_GET_INVOICES_BY_MERCHANT_ID :
              return new ProcessGetInvoicesByMerchantIdTransaction;

            case _TRANSACTION_GET_INVOICES_BY_RESELLER_ID :
                return new ProcessGetInvoicesByResellerIdTransaction;

            case _TRANSACTION_GET_SECURITY_TICKETS_BY_MERCHANT_BY_ID:
                return new ProcessGetSecurityTicketsByMerchantIdTransaction;

            case _TRANSACTION_GET_SECURITY_TICKETS_BY_RESELLER_BY_ID:
                return new ProcessGetSecurityTicketsByResellerIdTransaction;

            case _TRANSACTION_GET_TICKETS_BY_MERCHANT:
                return new ProcessGetTicketsByMerchantTransaction;

            case _TRANSACTION_GET_TICKETS_BY_RESELLER:
                return new ProcessGetTicketsByResellerTransaction;

            case _TRANSACTION_GET_COUNTRIES:
                return new ProcessGetCountriesTransaction;

            case _TRANSACTION_GET_CATEGORY_BY_ID:
                return new ProcessGetCategoryByIDTransaction;

            case _TRANSACTION_GET_STATES_BY_COUNTRY_CODE:
                return new ProcessGetStatesByCountryCodeTransaction;

            case _TRANSACTION_GET_SUBCATEGORIES_BY_PARENT_ID:
                return new ProcessGetSubCategoriesByParentIDTransaction;

            case _TRANSACTION_GET_CONSUMER_BY:
                return new ProcessGetConsumerByTransaction;

            case _TRANSACTION_GET_MERCHANT_BY:
                return new ProcessGetMerchantByTransaction;

            case _TRANSACTION_GET_RESELLER_BY:
                return new ProcessGetResellerByTransaction;

            case _TRANSACTION_GET_INVOICES_BY_DATE:
                return new ProcessGetInvoicesByDateTransaction;

            case  _TRANSACTION_SEARCH_USER_CONSUMER:
                return new ProcessSearchUserConsumerTransaction;

            case  _TRANSACTION_SEARCH_USER_MERCHANT:
                return new ProcessSearchUserMerchantTransaction;

            case  _TRANSACTION_SEARCH_USER_RESELLER:
                return new ProcessSearchUserResellerTransaction;

            case _TRANSACTION_ADMIN_NEW_CONSUMER:
                return new ProcessAdminNewConsumerTransaction;

            case _TRANSACTION_ADMIN_NEW_MERCHANT:
                return new ProcessAdminNewMerchantTransaction;

            case _TRANSACTION_ADMIN_NEW_RESELLER:
                return new ProcessAdminNewResellerTransaction;

            case _TRANSACTION_ADD_NEW_COUPON:
                return new ProcessAddNewCouponTransaction;

            case _TRANSACTION_ADD_NEW_PROMOTION:
                return new ProcessAddNewPromotionTransaction;

            case _TRANSACTION_REGISTER_MERCHANT:
                return new ProcessRegisterMerchantTransaction;

            case _TRANSACTION_ADD_MERCHANT_ACCOUNT_NAME:
                return new ProcessAddMerchantAccountNameTransaction;

            case _TRANSACTION_ADD_STORE_MERCHANT:
                return new ProcessAddStoreMerchantTransaction;

            case _TRANSACTION_REGISTER_CONSUMER:
                return new ProcessRegisterConsumerTransaction;

            case _TRANSACTION_ADD_NEW_CLUB_AND_MEMBERSHIP:
                return new ProcessAddNewClubAndMembershipTransaction;

            case _TRANSACTION_GET_COUPON:
                return new ProcessGetCouponTransaction;

            case _TRANSACTION_GET_PROMOTION:
                return new ProcessGetPromotionTransaction;


            case _TRANSACTION_GET_COUPON_BY_MERCHANT_ID:
                return new ProcessGetCouponByMerchantIdTransaction;

            case _TRANSACTION_GET_PROMOTION_BY_MERCHANT_ID:
                return new ProcessGetPromotionByMerchantIdTransaction;

            case _TRANSACTION_GET_CLUBS_AND_MEMBERSHIPS_BY_MERCHANT_ID:
                return new ProcessGetClubsAndMembershipsByMerchantIdTransaction;

            case _TRANSACTION_ADD_NEW_LOG:
                return new ProcessAddLogTransaction;

            case _TRANSACTION_GET_LOGS:
                return new ProcessGetLogsTransaction;

            case _TRANSACTION_GET_MERCHANT_COUPON_FILTER:
                return new ProcessGetMerchantCouponFilterTransaction;

            case _TRANSACTION_GET_MERCHANT_PROMOTION_FILTER:
                return new ProcessGetMerchantPromotionFilterTransaction;

            case _TRANSACTION_GET_MERCHANT_CLUBS_AND_MEMBERSHIPS_FILTER:
                return new ProcessGetMerchantClubsAndMembershipsFilterTransaction;

			case _TRANSACTION_GET_CONSUMER_COUPON_FILTER:
                return new ProcessGetConsumerCouponFilterTransaction;



            case _TRANSACTION_GET_CONSUMER_CLUBS_AND_MEMBERSHIPS_FILTER:
                return new ProcessGetConsumerClubsAndMembershipsFilterTransaction;

            case _TRANSACTION_ADD_LOCATION_TO_LOYALTY_PROGRAM:
                return new ProcessAddLocationToLoyaltyProgramTransaction;

            case _TRANSACTION_REMOVE_LOCATION_TO_LOYALTY_PROGRAM:
                return new ProcessRemoveLocationToLoyaltyProgramTransaction;

            case _TRANSACTION_GET_LOYALTY_PROGRAMS_BY_LOCATION_ID:
                return new ProcessGetLoyaltyProgramsByLocationIdTransaction;

			case _TRANSACTION_ADD_REMOTE_ITEMS_TO_LOYALTY_PROGRAM:
				return new ProcessAddRemoteItemsToLoyaltyProgramTransaction;

			case _TRANSACTION_REMOVE_REMOTE_ITEMS_TO_LOYALTY_PROGRAM:
				return new ProcessRemoveRemoteItemsToLoyaltyProgramTransaction;

			case _TRANSACTION_GET_REMOTE_ITEMS_BY_LOYALTY_PROGRAM_ID:
				return new ProcessGetRemoteItemsByLoyaltyProgramsIdTransaction;

            case _TRANSACTION_ADD_SHOPPING_LIST:
                return new ProcessAddShoppingListTransaction;

            case _TRANSACTION_REMOVE_SHOPPING_LIST:
                return new ProcessRemoveShoppingListTransaction;

            case _TRANSACTION_ADD_ITEMS_TO_SHOPPING_LIST:
                return new ProcessAddItemsToShoppingListTransaction;

            case _TRANSACTION_REMOVE_ITEMS_TO_SHOPPING_LIST:
                return new ProcessRemoveItemsToShoppingListTransaction;

            case _TRANSACTION_EDIT_SHOPPING_LIST_NAME:
                return new ProcessEditShoppingListNameTransaction;

            case _TRANSACTION_GET_SHOPPING_LIST_BY_CONSUMER_ID:
                return new ProcessGetShoppingListByConsumerIdTransaction;

            case _TRANSACTION_GET_LOYALTY_PROGRAMS_BY_REMOTE_ITEM_ID:
                return new ProcessGetLoyaltyProgramsByRemoteItemIdTransaction;

            case _TRANSACTION_GET_NAME_SHOPPING_LIST_BY_CONSUMER_ID:
                return new ProcessGetNameShoppingListByConsumerIdTransaction;

            case _TRANSACTION_GET_SHOPPING_REMOTE_ITEMS_FILTER:
                return new ProcessGetShoppingRemoteItemsFilterTransaction;

            case _TRANSACTION_GET_SHOPPING_LOYALTY_PROGRAMS_FILTER:
                return new ProcessGetShoppingLoyaltyProgramsFilterTransaction;

            case _TRANSACTION_GET_REMOTE_ITEMS_BY_MERCHANT_ID:
                return new ProcessGetRemoteItemsByMerchantIdTransaction;

            case _TRANSACTION_ADD_NEW_REMOTE_ITEM:
                return new ProcessAddNewRemoteItemTransaction;

            case _TRANSACTION_GET_SHOPPING_LIST_NAME:
                return new ProcessGetShoppingListNameTransaction;

            case _TRANSACTION_GET_CREDIT_CARD_BY_CONSUMER_ID:
                return new ProcessGetCreditCardByConsumerIDTransaction;

            case _TRANSACTION_TOTAL_SALES_PER_DAY:
                return new ProcessTotalSalesPerDayTransaction;

            case _TRANSACTION_ADD_NEW_SHIPPING_OPTIONS:
                return new ProcessAddNewShippingOptionsTransaction;

            case _TRANSACTION_GET_SHIPPING_OPTION:
                return new ProcessGetShippingOptionTransaction;

            case _TRANSACTION_EDIT_SHIPPING_OPTIONS:
                return new ProcessEditShippingOptionsTransaction;

            case _TRANSACTION_REMOVE_SHIPPING_OPTIONS:
                return new ProcessRemoveShippingOptionsTransaction;

            case _TRANSACTION_GET_COUPON_BY_ID:
                return new ProcessGetCouponByIDTransaction;

            case _TRANSACTION_GET_CLUBS_AND_MEMBERSHIPS_BY_ID:
                return new ProcessGetClubsAndMembershipsByIdTransaction;

            case _TRANSACTION_GET_PROMOTION_BY_ID:
                return new ProcessGetPromotionByIdTransaction;

            case _TRANSACTION_IS_FAVORITE_MERCHANT:
                return new ProcessIsFavoriteMerchantTransaction;

            case _TRANSACTION_GET_INVOICES_CONSUMER_FILTER:
                return new ProcessGetInvoicesConsumerFilterTransaction;

            case _TRANSACTION_MOVE_ITEM_BETWEEN_SHOPPING_LIST:
                return new ProcessMoveItemBetweenShoppingListTransaction;

            case _TRANSACTION_GET_RATINGS_AND_REVIEWS_BY_CONSUMER_ID:
                return new ProcessGetRatingsAndReviewsByConsumerIdTransaction;

            case _TRANSACTION_GET_CONSUMER_GET_RATINGS_AND_REVIEWS_FILTER:
                return new ProcessGetConsumerRatingsandReviewsFilterTransaction;

            case _TRANSACTION_GET_COUPON_TO_EXPIRE_BY_CONSUMER_ID:
                return new ProcessGetCouponToExpireByConsumerIdTransaction;

            case _TRANSACTION_GET_ADDRESS_BY_CONSUMER_ID:
                return new ProcessGetAddressByConsumerIdTransaction;

            case _TRANSACTION_CHANGE_PASSCODE:
                return new ProcessChangePasscodeTransaction;

            case _TRANSACTION_EDIT_LANGUAGE_AND_LOCK_TIME:
                return new ProcessEditLanguageAndLockTimeTransaction;

            case _TRANSACTION_GET_LAST_COUPON_CREATED_BY_MERCHANT_ID:
                return new ProcessGetLastCouponCreatedByMerchantIdTransaction;

            case _TRANSACTION_REGISTER_USER_MERCHANT:
                return new ProcessRegisterUserMerchantTransaction;

            case _TRANSACTION_GET_RATINGS_AND_REVIEWS_BY_ID:
                return new ProcessGetRatingsandReviewsbyIdTransaction;

            case _TRANSACTION_REPLAY_RATINGS_AND_REVIEWS:
                return new ProcessReplayRatingsAndReviewsTransaction;

            case _TRANSACTION_REPORT_TO_NMC:
                return new ProcessReportToNMCTransaction;

            case _TRANSACTION_GET_RECENT_MESSAGE_SYSTEM_BY_MERCHANT_ID:
                return new ProcessGetRecentMessageSystemByMerchantIDTransaction;

            case _TRANSACTION_GET_HELP_TICKETS_BY_ID:
                return new ProcessGetHelpTicketsByIdTransaction;

            case _TRANSACTION_GET_TICKETS_BY_PARENT_ID:
                return new ProcessGetTicketsByParentIdTransaction;

            case _TRANSACTION_ADD_NEW_ACTION:
                return new ProcessAddNewActionTransaction;

            case _TRANSACTION_GET_INVOICES_BY_DATE_AND_MERCHANT_ID:
                return new ProcessGetInvoicesByDateAndMerchantIdTransaction;

            case _TRANSACTION_ADD_NEW_HELP_TICKETS:
                return new ProcessAddNewHelpTicketsTransaction;

            case _TRANSACTION_GET_LIST_RESELLER_COMPANY_NAME:
                return new ProcessGetListResellerCompanyNameTransaction;

            case _TRANSACTION_GET_RATINGS_AND_REVIEWS_BY_PARENT_ID:
                return new ProcessGetRatingsandReviewsbyParentIdTransaction;

            case _TRANSACTION_GET_CATEGORY_OF_BUSINESS_LIST:
                return new ProcessGetCategoryOfBusinessListTransaction;

            case _TRANSACTION_GET_SUBCATEGORY_OF_BUSINESS_BY_PARENT_ID_LIST:
                return new ProcessGetSubcategoryOfBusinessByParentIdListTransaction;

            case _TRANSACTION_VALIDATE_RATING_AND_REVIEW_IS_REPORTED_TO_NMC:
                return new ProcessValidateRartingAndReviewIsReportedToNMCTransaction;

            case _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_LOTALTY:
                return new ProcessAddNewMerchantPermissionLoyaltyTransaction;

            case _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_REMOTE:
                return new ProcessAddNewMerchantPermissionRemoteTransaction;

            case _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_ACCOUNTING:
                return new ProcessAddNewMerchantPermissionAccountingTransaction;

            case _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_TRANSACTIONS:
                return new ProcessAddNewMerchantPermissionTransactionsTransaction;

            case _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_SUBSCRIPTIONS:
                return new ProcessAddNewMerchantPermissionSubscriptionsTransaction;

            case _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_REVIEWS:
                return new ProcessAddNewMerchantPermissionReviewsTransaction;

            case _TRANSACTION_ADD_NEW_MERCHANT_PERMISSION_USERS:
                return new ProcessAddNewMerchantPermissionUsersTransaction;

            case _TRANSACTION_GET_PERMISSION_TRANSACTIONS_BY_MERCHANT_ID:
                return new ProcessGetPermissionTransactionsByMerchantIDTransaction;

            case _TRANSACTION_GET_PERMISSION_SUBSCRIPTIONS_BY_MERCHANT_ID:
                return new ProcessGetPermissionSubscriptionsByMerchantIDTransaction;

            case _TRANSACTION_GET_PERMISSION_REVIEWS_BY_MERCHANT_ID:
                return new ProcessGetPermissionReviewsByMerchantIDTransaction;

            case _TRANSACTION_GET_PERMISSION_LOYALTY_BY_MERCHANT_ID:
                return new ProcessGetPermissionLoyaltyByMerchantIDTransaction;

            case _TRANSACTION_GET_PERMISSION_ACCOUNTING_BY_MERCHANT_ID:
                return new ProcessGetPermissionAccountingByMerchantIDTransaction;

            case _TRANSACTION_GET_PERMISSION_REMOTE_BY_MERCHANT_ID:
                return new ProcessGetPermissionRemoteByMerchantIDTransaction;

            case _TRANSACTION_GET_PERMISSION_USER_BY_MERCHANT_ID:
                return new ProcessGetPermissionUserByMerchantIdTransaction;

            case _TRANSACTION_GET_IMAGES_BY_LOYALTY_ID:
                return new ProcessGetImagesByLoyaltyIDTransaction;

            case _TRANSACTION_GET_LOYALTY_PROGRAMS_BY_USER_MERCHANT:
                return new ProcessGetLoyaltyProgramsByUserMerchantTransaction;

            case _TRANSACTION_GET_CATEGORY_BY_PARENT_ID:
                return new ProcessGetCategoryByParentIdTransaction;

            case _TRANSACTION_GET_CATEGORY_BY_TYPE:
                return new ProcessGetCategoryByTypeTransaction;

            case _TRANSACTION_GET_TYPES_OF_CATEGORIES:
                return new ProcessGetTypesOfCategoriesTransaction;

            case _TRANSACTION_GET_LOCATIONS_BY_MERCHANT_ID:
                return new ProcessGetLocationsByMerchantIdTransaction;

            case _TRANSACTION_ADD_IMAGES_TO_LOYALTY_PROGRAMS:
                return new ProcessAddImagesToLoyaltyProgramsTransaction;

            case _TRANSACTION_ADD_LOCATIONS_TO_LOYALTY_PROGRAMS:
                return new ProcessAddlocationsToLoyaltyProgramsTransaction;

            case _TRANSACTION_GET_COUNTRY_CURRENCY_CODE:
                return new ProcessGetCountryCurrencyCodeTransaction;

            case _TRANSACTION_ADD_IMAGES_TO_REMOTE_ITEMS:
                return new ProcessAddImagesToRemoteItemsTransaction;

            case _TRANSACTION_GET_COMPANY_NAME_BY_MERCHANT_ID:
                return new ProcessGetCompanyNameByMerchantIdTransaction;

            case _TRANSACTION_ADD_NEW_CATALOG:
                return new ProcessAddNewCatalogTransaction;

            case _TRANSACTION_GET_CHOICES_BY_OPTION_ID :
                return new ProcessGetChoicesByOptionIdTransaction;

             case _TRANSACTION_GET_OPTIONS_BY_REMOTE_ID :
                return new ProcessGetOptionsByRemoteIdTransaction;

             case _TRANSACTION_GET_TOTAL_BY_OPTION_ID :
                return new ProcessGetTotalByOptionIdTransaction;

             case _TRANSACTION_ADD_NEW_CHOICE :
                return new ProcessAddNewChoiceTransaction;

             case _TRANSACTION_ADD_NEW_OPTION :
                return new ProcessAddNewOptionTransaction;

             case _TRANSACTION_ADD_TOTAL_BY_OPTION_ID :
                return new ProcessAddTotalByOptionIdTransaction;

            case _TRANSACTION_GET_CATALOGS_BY_MERCHANT_ID:
                return new ProcessGetCatalogsByMerchantIdTransaction;

            case _TRANSACTION_GET_CITIES_BY_STATE_ID:
                return new ProcessGetCitiesByStateIdTransaction;

             case _TRANSACTION_REMOVE_CATALOG :
                return new ProcessRemoveCatalogTransaction;

            case _TRANSACTION_MOVE_TO_CATALOG:
                return new ProcessMoveToCatalogTransaction;

              case _TRANSACTION_REMOVE_ITEMS_FROM_CATALOG:
                return new ProcessRemoveItemsFromCatalogTransaction;

            case _TRANSACTION_GET_REMOTE_ITEMS_BY_CATALOG_ID:
                return new ProcessGetRemoteItemsByCatalogIdTransaction;


            case _TRANSACTION_GET_MESSAGE_BY_INVOICE_ID:
                return new ProcessGetMessageByInvoiceIdTransaction;

            case _TRANSACTION_GET_MESSAGE_BY_MERCHANT_ID:
                return new ProcessGetMessageByMerchantIdTransaction;

            case _TRANSACTION_GET_TRANSACTIONS_BY_MERCHANT_ID:
                return new ProcessGetTransactionsByMerchantIdTransaction;

            case _TRANSACTION_ADD_NEW_INVOICE_MESSAGE:
                return new ProcessAddNewInvoiceMessageTransaction;

            case _TRANSACTION_ADD_NEW_INVOICE_NOTE:
                return new ProcessAddNewInvoiceNoteTransaction;

            case _TRANSACTION_GET_SEQ_IMAGES_NAME:
                return new ProcessGetSeqImagesNameTransaction;

            case _TRANSACTION_GET_INVOICE_DETAILS_CATALOG_BY_MERCHANT_ID:
                return new ProcessGetInvoiceDetailsCatalogByMerchantIdTransaction;

            case _TRANSACTION_GET_INVOICE_DETAILS_LOYALTY_BY_MERCHANT_ID:
                return new ProcessGetInvoiceDetailsLoyaltyByMerchantIdTransaction;

            case _TRANSACTION_GET_INVOICE_DETAILS_REMOTE_ITEMS_BY_MERCHANT_ID:
                            return new ProcessGetInvoiceDetailsRemoteItemsByMerchantIdTransaction;

            case _TRANSACTION_GET_NOTES_BY_INVOICE_ID:
                return new ProcessGetNotesByInvoiceIdTransaction;

            case _TRANSACTION_UPDATE_SHIPPING_STATUS_TRANSACTION:
                return new ProcessUpdateShippingStatusTransactionTransaction;

            case _TRANSACTION_GET_TERMINALS_BY_LOCATION_ID:
                return new ProcessGetTerminalsByLocationIdTransaction;

            case _TRANSACTION_PROFILE_GET_MERCHANT_BY_ID:
                return new ProcessProfileGetMerchantByIdTransaction;

            case _TRANSACTION_ADD_NEW_TERMINAL:
                return new ProcessAddNewTerminalTransaction;

            case _TRANSACTION_DELETE_CREDIT_CARD_MERCHANT:
                return new ProcessDeleteCreditCardMerchantTransaction;

             case _TRANSACTION_REMOVE_TERMINALS:
                return new ProcessDeleteTerminalsTransaction;

              case _TRANSACTION_ENABLE_LOCATIONS :
               return new ProcessEnableLocationsTransaction;

              case _TRANSACTION_GET_CREDIT_CARD_BY_MERCHANT_ID:
                return new ProcessGetCreditCardByMerchantIdTransaction;

            case _TRANSACTION_GET_BILLING_HISTORY_MERCHANT_BY_MERCHANT_ID:
                return new ProcessGetBillingHistoryMerchantByMerchantIdTransaction;

            case _TRANSACTION_GET_INACTIVE_LOCATIONS_BY_MERCHANT_ID:
                return new ProcessGetInactiveLocationsByMerchantIdTransaction;

             case _TRANSACTION_SET_FAVORITE_CREDIT_CARD_MERCHANT:
                return new ProcessSetFavoriteCreditCardMerchantTransaction;


             case _TRANSACTION_GET_PAYMENT_METHOD_BY_MERCHANT_ID :
                return new ProcessGetPaymentMethodByMerchantIdTransaction;

             case _TRANSACTION_GET_TYPE_OF_BUSINESS_BY_MERCHANT_ID :
                return new ProcessGetTypeOfBusinessByMerchantIdTransaction;

             case _TRANSACTION_PROFILE_ADD_PAYMENT_METHOD :
                return new ProcessProfileAddPaymentMethodTransaction;

            case _TRANSACTION_PROFILE_REMOVE_PAYMENT_METHOD :
                return new ProcessProfileRemovePaymentMethodTransaction;

             case _TRANSACTION_PROFILE_EDIT_USER_MERCHANT :
                return new ProcessProfileEditUserMerchantTransaction;

             case _TRANSACTION_GET_USERS_MERCHANT_BY_PARENT_ID :
                    return new ProcessGetUsersMerchantByParentIdTransaction;

            case _TRANSACTION_ADD_NEW_CONTACT_US_MERCHANT:
                return new ProcessAddNewContactUsMerchantTransaction;

             case _TRANSACTION_GET_HELP_TICKETS_BY_MERCHANT_ID :
                return new ProcessGetHelpTicketsByMerchantIdTransaction;

            case _TRANSACTION_SUSPEND_USERS_MERCHANT:
                return new ProcessSuspendUsersMerchantTransaction;

            case _TRANSACTION_DELETE_LOYALTY_PROGRAM_BY_ID:
                return new ProcessDeleteLoyaltyProgramByIdTransaction;

            case _TRANSACTION_DELETE_REMOTE_ITEM_BY_ID:
                return new ProcessDeleteRemoteItemByIdTransaction;

            case _TRANSACTION_EDIT_LOYALTY_PROGRAMS_BY_ID :
                return new ProcessEditLoyaltyProgramsByIdTransaction;

             case _TRANSACTION_EDIT_REMOTE_ITEM_BY_ID :
                return new ProcessEditRemoteItemByIdTransaction;

            case _TRANSACTION_GET_BILLING_HISTORY_LIST_MERCHANT_BY_MERCHANT_ID_FILTER:
                return new ProcessGetBillingHistoryListMerchantByMerchantIdFilterTransaction;

             case _TRANSACTION_GET_HELP_TICKETS_BY_MERCHANT_ID_FILTER:
                return new ProcessGetHelpTticketsByMerchantIdFilterTransaction;

            case _TRANSACTION_SEARCH_HELP_TICKETS_BY_MERCHANT_ID:
                return new ProcessSearchHelpTticketsByMerchantIdTransaction;

             case _TRANSACTION_SEARCH_LOYALTY_PROGRAMS_BY_MERCHANT_ID :
                return new ProcessSearchLoyaltyProgramsByMerchantIdTransaction;

            case _TRANSACTION_EDIT_MERCHANT_PERMISSION_ACCOUNTING:
                return new ProcessEditMerchantPermissionAccountingTransaction;

            case _TRANSACTION_EDIT_MERCHANT_PERMISSION_LOYALTY:
                return new ProcessEditMerchantPermissionLoyaltyTransaction;

              case _TRANSACTION_EDIT_MERCHANT_PERMISSION_REMOTE:
                return new ProcessEditMerchantPermissionRemoteTransaction;

            case _TRANSACTION_EDIT_MERCHANT_PERMISSION_REVIEWS:
                return new ProcessEditMerchantPermissionReviewsTransaction;

            case _TRANSACTION_EDIT_MERCHANT_PERMISSION_SUBSCRIPTIONS:
                return new ProcessEditMerchantPermissionSubscriptionsTransaction;

            case _TRANSACTION_EDIT_MERCHANT_PERMISSION_TRANSACTIONS:
                return new ProcessEditMerchantPermissionTransactionsTransactions;

            case _TRANSACTION_EDIT_MERCHANT_PERMISSION_USERS:
                return new ProcessEditMerchantPermissionUsersTransactions;

             case _TRANSACTION_GET_CATALOG_LOYALTY_REMOTE_BY_MERCHANT_ID_FOR_ADD:
                return new ProcessGetCatalogLoyaltyRemoteByMerchantIdForAddTransaction;

            case _TRANSACTION_GET_REMOTE_ITEMS_BY_MERCHANT_ID_FILTER:
                return new ProcessGetRemoteItemsByMerchantIdFilterTransaction;

            case _TRANSACTION_SEARCH_REMOTE_ITEMS_BY_CATALOG_ID:
                return new ProcessSearchRemoteItemsByCatalogIdTransaction;

            case _TRANSACTION_SEARCH_REMOTE_ITEMS_BY_MERCHANT_ID:
                return new ProcessSearchRemoteItemsByMerchantIdTransaction;

            case _TRANSACTION_GET_REMOTE_ITEMS_BY_CATALOG_ID_FILTER:
                return new ProcessGetRemoteItemsByCatalogIdFilterTransaction;

            case _TRANSACTION_SEARCH_USERS_MERCHANT_BY_PARENT_ID:
                return new ProcessSearchUsersMerchantByParentIdTransaction;

            case _TRANSACTION_GET_USERS_MERCHANT_BY_PARENT_ID_FILTER:
                return new ProcessGetUsersMerchantByParentIdFilterTransaction;

             case _TRANSACTION_SEARCH_MERCHANT_RATINGS:
                return new ProcessSearchMerchantRatingsTransaction;

            case _TRANSACTION_GET_MERCHANT_RATINGS_FILTER:
                return new ProcessGetMerchantRatingsFilterTransaction;

            case _TRANSACTION_ACCEPT_NEW_TRANSACTION:
                return new ProcessAcceptNewTransactionTransaction;

             case _TRANSACTION_ADD_NEW_PRODUCT_TRANSACTION:
                return new ProcessAddNewProductTransactionTransaction;

             case _TRANSACTION_ADD_NEW_TEMPORAL_TRANSACTION:
                return new ProcessAddNewTemporalTransactionTransaction;

            case _TRANSACTION_ADD_REFUND_BY_TRANSACTION_PRODUCT_ID:
                return new ProcessAddRefundByTransactionProductIdTransaction;

            case _TRANSACTION_GET_TRANSACTIONS_BY_MERCHANT_ID_FILTER:
                return new ProcessGetTransactionsByMerchantIdFilterTransaction;

             case _TRANSACTION_SEARCH_TRANSACTIONS_BY_MERCHANT_ID:
                return new ProcessSearchTransactionsByMerchantIdTransaction;

            case _TRANSACTION_CONFIRM_MERCHANT_PASSWORD:
                return new ProcessConfirmMerchantPasswordTransaction;

            case _TRANSACTION_GET_TRANSACTION_BY_ID:
                return new ProcessGetTransactionByIdTransaction;

            case _TRANSACTION_GET_HELP_TICKETS_BY_CONSUMER_ID:
                return new ProcessGetHelpTicketsByConsumerIdTransaction;

            case _TRANSACTION_GET_RECENT_INVOICES_BY_CONSUMER_ID:
                return new ProcessGetRecentInvoicesByConsumerIdTransaction;

            case _TRANSACTION_SEARCH_INVOICES_BY_CONSUMER_ID:
                return new ProcessSearchInvoicesByConsumerIdTransaction;

             case _TRANSACTION_EDIT_TERMINAL:
                return new ProcessEditTerminalTransaction;

            case _TRANSACTION_GET_TRANSACTIONS_BY_CARD_TOCKEN:
                return new ProcessGetTransactionsByCardTockenTransaction;

           case _TRANSACTION_SEARCH_TRANSACTIONS_BY_CARD_TOCKEN:
                return new ProcessSearchTransactionsByCardTockenTransaction;

            case _TRANSACTION_GET_TRANSACTIONS_BY_CARD_TOCKEN_FILTER:
                return new ProcessGetTransactionsByCardTockenFilterTransaction;

            case _TRANSACTION_ADD_NEW_CREDIT_CARD_MERCHANT:
                return new ProcessAddNewCreditCardMerchantTransaction;

             case _TRANSACTION_COUNTER_ACCOUNTS_BY_CONSUMER_ID:
                return new ProcessCounterAccountsByConsumerIdTransaction;

              case _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID:
                return new ProcessGetClubAndMembershipByConsumerIdTransaction;

            case _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID_FILTER:
                return new ProcessGetClubAndMembershipByConsumerIdFilterTransaction;


            case _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_BY_SHOPPING_LIST_ID:
                return new ProcessGetClubAndMembershipByShoppingListIdTransaction;

             case _TRANSACTION_GET_CLUB_AND_MEMBERSHIP_IN_SHOPPING_LIST_BY_CONSUMER_ID:
                return new ProcessGetClubAndMembershipInShoppingListByConsumerIdTransaction;




            case _TRANSACTION_GET_CONSUMER_COUPON_FILTER_BY_SHOPPING_LIST_ID:
                return new ProcessGetConsumerCouponFilterByShoppingListIdTransaction;

             case _TRANSACTION_GET_CONSUMER_COUPON:
                return new ProcessGetConsumerCouponTransaction;

             case _TRANSACTION_GET_STATUS_FACEBOOK_TWITTER_BY_CONSUMER_ID:
                return new ProcessGetStatusFacebookTwitterByConsumerIdTransaction;



             case _TRANSACTION_GET_CONSUMER_PROMOTION_FILTER:
                return new ProcessGetConsumerPromotionFilterTransaction;

            case _TRANSACTION_GET_CONSUMER_PROMOTION_FILTER_BY_SHOPPING_LIST_ID:
                return new ProcessGetConsumerPromotionFilterByShoppingListIdTransaction;

            case _TRANSACTION_GET_CONSUMER_PROMOTIONS:
                return new ProcessGetConsumerPromotionsTransaction;

            case _TRANSACTION_GET_CONSUMER_REMOTE_ITEM:
                return new ProcessGetConsumerRemoteItemTransaction;

            case _TRANSACTION_GET_COUPON_BY_SHOPPING_LIST_ID:
                return new ProcessGetCouponByShoppingListIdTransaction;



             case _TRANSACTION_GET_EXPIRING_IN_SEVEN_DAYS_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID:
                return new ProcessGetExpiringInSevenDaysClubAndMembershipByConsumerIdTransaction;

            case _TRANSACTION_GET_JOINED_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID:
                return new ProcessGetJoinedClubAndMembershipByConsumerIdTransaction;

            case _TRANSACTION_GET_JOIN_NOW_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID:
                return new ProcessGetJoinNowClubAndMembershipByConsumerIdTransaction;

            case _TRANSACTION_GET_PROMOTIONS_BY_SHOPPING_LIST_ID:
                return new ProcessGetPromotionsByShoppingListIdTransaction;

            case _TRANSACTION_GET_REMOTE_ITEM_BY_SHOPPING_LIST_ID:
                return new ProcessGetRemoteItemByShoppingListIdTransaction;

            case _TRANSACTION_SEARCH_CONSUMER_COUPON_AND_PROMOTION:
                return new ProcessSearchConsumerCouponAndPromotionTransaction;

             case _TRANSACTION_SEARCH_CONSUMER_COUPON_AND_PROMOTION_BY_SHOPPING_LIST_ID:
                return new ProcessSearchConsumerCouponAndPromotionByShoppingListIdTransaction;


            case _TRANSACTION_SEARCH_GET_CLUB_AND_MEMBERSHIP_BY_CONSUMER_ID:
                return new ProcessSearchGetClubAndMembershipByConsumerIdTransaction;

            case _TRANSACTION_SEARCH_REMOTE_ITEM_BY_SHOPPING_LIST_ID:
                return new ProcessSearchRemoteItemByShoppingListIdTransaction;

            case _TRANSACTION_GET_CONSUMER_CLUB_AND_MEMBERSHIP_FILTER_BY_SHOPPING_LIST_ID:
                return new ProcessGetConsumerClubAndMembershipFilterByShoppingListIdTransaction;

            case _TRANSACTION_SAVE_SECRET_QUESTION_BY_CONSUMER_ID:
                return new ProcessSaveSecretQuestionByConsumerIdTransaction;

            case _TRANSACTION_ADD_PAYMENT_ACCOUNT_CONSUMER:
                return new ProcessAddPaymentAccountConsumerTransaction;

            case _TRANSACTION_EDIT_PAYMENT_ACCOUNT_CONSUMER_BY_ID:
                return new ProcessEditPaymentAccountConsumerByIdTransaction;

            case _TRANSACTION_ADD_IMAGES_TO_PRODUCT_BY_CONSUMER:
                return new ProcessAddImagesToProductByConsumerTransaction;

            case _TRANSACTION_VALIDATE_CONSUMER_PASSWORD:
                return new ProcessValidateConsumerPasswordTransaction;

             case _TRANSACTION_VALIDATE_CONSUMER_PINCODE:
                return new ProcessValidateConsumerPincodeTransaction;

            case _TRANSACTION_REMOVE_PAYMENT_ACCOUNT_CONSUMER_BY_ID:
                return new ProcessRemovePaymentAccountConsumerByIdTransaction;

            case _TRANSACTION_GET_SALE_ITEMS_BY_CONSUMER_ID:
                return new ProcessGetSaleItemsByConsumerIdTransaction;

            case _TRANSACTION_SEARCH_SALE_ITEMS_BY_CONSUMER_ID:
                return new ProcessSearchSaleItemsByConsumerIdTransaction;

            case _TRANSACTION_GET_SALE_ITEMS_BY_CONSUMER_ID_FILTER:
                return new ProcessGetSaleItemsByConsumerIdFilterTransaction;

            case _TRANSACTION_ADD_NEW_CONSUMER_ADDRESS:
                return new ProcessAddNewConsumerAddressTransaction;

             case _TRANSACTION_SET_DEFAULT_CONSUMER_ADDRESS:
                return new ProcessSetDefaultConsumerAddressTransaction;

            case _TRANSACTION_EDIT_CONSUMER_ADDRESS:
                return new ProcessEditConsumerAddressTransaction;

            case _TRANSACTION_REMOVE_CONSUMER_ADDRESS_BY_ID:
                return new ProcessRemoveConsumerAddressByIdTransaction;

            case _TRANSACTION_GET_CONSUMER_ADDRESS_BY_CONSUMER_ID:
                return new ProcessGetConsumerAddressByConsumerIdTransaction;

            case _TRANSACTION_ADD_NEW_OPTION_CONSUMER :
                return new ProcessAddNewOptionConsumerTransaction;

             case _TRANSACTION_ADD_TOTAL_BY_OPTION_ID_CONSUMER :
                return new ProcessAddTotalByOptionIdConsumerTransaction;

             case _TRANSACTION_SET_STATUS_FACEBOOK_TWITTER_BY_CONSUMER_ID:
                return new ProcessSetStatusFacebookTwitterByConsumerIdTransaction;

            case _TRANSACTION_GET_LANGUAGE_SCREEN_LOCK_TIME_BY_CONSUMER_ID:
                return new ProcessGetLanguageScreenLockTimeByConsumerIdTransaction;

            case _TRANSACTION_SET_LANGUAGE_SCREEN_LOCK_TIME_BY_CONSUMER_ID:
                return new ProcessSetLanguageScreenLockTimeByConsumerIdTransaction;

            case _TRANSACTION_CHANGE_MAIL_CONSUMER:
                return new ProcessChangeMailConsumerTransaction;

            case _TRANSACTION_CONTACT_NMC_CONSUMER:
                return new ProcessContactNMCConsumerTransaction;

            case _TRANSACTION_ADD_NEW_SALE_ITEM:
                return new ProcessAddNewSaleItemTransaction;

            case _TRANSACTION_EDIT_SALE_ITEM:
                return new ProcessEditSaleItemTransaction;

            case _TRANSACTION_REMOVE_SALE_ITEM:
                return new ProcessRemoveSaleItemTransaction;

            case _TRANSACTION_SAVE_STATUS_LOST_PHONE:
                return new ProcessSaveStatusLostPhoneTransaction;

            case _TRANSACTION_GET_CONSUMER_NOTIFICATIONS_SETTINGS:
                return new ProcessGetConsumerNotificationSettingsTransaction;

            case _TRANSACTION_EDIT_CONSUMER_NOTIFICATIONS_SETTINGS:
                return new ProcessEditConsumerNotificationSettingsTransaction;

            case _TRANSACTION_DELETE_USER_MERCHANT:
                return new ProcessDeleteUserMerchantTransaction;

            case _TRANSACTION_EDIT_CREDIT_CARD_MERCHANT:
                return new ProcessEditCreditCardMerchantTransaction;

            case _TRANSACTION_CONTACT_NMC_RESELLER:
                return new ProcessContactNMCResellerTransaction;

            case _TRANSACTION_GET_RESELLER_RATINGS_AND_REVIEWS:
                return new ProcessGetResellerRatingsAndReviewsTransaction;

            case _TRANSACTION_SEARCH_RESELLER_RATINGS_AND_REVIEWS:
                return new ProcessSearchResellerRatingsAndReviewsTransaction;

            case _TRANSACTION_GET_RESELLER_RATINGS_FILTER:
                return new ProcessGetResellerRatingsFilterTransaction;

            case _TRANSACTION_GET_RESELLER_HELP_TICKETS_FROM_MERCHANT:
                return new ProcessGetResellerHelpTicketsfromMerchantTransaction;

            case _TRANSACTION_GET_RESELLER_HELP_TICKETS_FROM_MERCHANT_FILTER:
                return new ProcessGetResellerHelpTicketsfromMerchantFilterTransaction;

            case _TRANSACTION_GET_RESELLER_HELP_TICKETS_TO_ADMIN:
                return new ProcessGetResellerHelpTicketsToAdminTransaction;

            case _TRANSACTION_GET_RESELLER_HELP_TICKETS_TO_ADMIN_FILTER:
                return new ProcessGetResellerHelpTicketsToAdminFilterTransaction;

            case _TRANSACTION_SEARCH_RESELLER_HELP_TICKETS_FROM_MERCHANT:
                return new ProcessSearchResellerHelpTicketsFromMerchantTransaction;

            case _TRANSACTION_SEARCH_RESELLER_HELP_TICKETS_TO_ADMIN:
                return new ProcessSearchResellerHelpTicketsToAdminTransaction;

            case _TRANSACTION_ADD_NEW_HELP_TICKETS_RESELLER:
                return new ProcessAddNewHelpTicketsResellerTransaction;

            case _TRANSACTION_GET_RESELLERS:
                return new ProcessGetResellersTransaction;

            case _TRANSACTION_GET_IMAGES_BY_REMOTE_ITEM_ID:
                return new ProcessGetImagesByRemoteItemIdTransaction;

            case _TRANSACTION_EDIT_MANAGEMENT_USER_MERCHANT:
                return new ProcessEditManagementUserMerchantTransaction;

            case _TRANSACTION_GET_SUPERVISOR_MERCHANT_BY_PARENT_ID:
                return new ProcessGetSupervisorMerchantByParentIdTransaction;

            case _TRANSACTION_GET_PATH_BY_NAME:
                return new ProcessGetPathByNameTransaction;

            case _TRANSACTION_EDIT_PATH:
                return new ProcessEditPathTransaction;

             case _TRANSACTION_ADD_NEW_PATH:
                return new ProcessAddNewPathTransaction;

            case _TRANSACTION_VALIDATE_NAME_PATH:
                return new ProcessValidateNamePathTransaction;

             case _TRANSACTION_GET_TERMINAL_BY_ID:
                return new ProcessGetTerminalByIdTransaction;

            case _TRANSACTION_GET_ZIP_CODE_BY_CITY:
                return new ProcessGetZipCodeByCityTransaction;

            case _TRANSACTION_REGISTER_TEMPORAL_USER:
                return new ProcessRegisterTemporalUserTransaction;

            case _TRANSACTION_ADD_NEW_PIN_CODE:
                return new ProcessAddNewPinCodeTransaction;

            case _TRANSACTION_FORGOT_PASSWORD_CONSUMER:
                return new ProcessForgotPasswordConsumerTransaction;

            case _TRANSACTION_GET_TEMPORAL_USER:
                return new ProcessGetTemporalUserTransaction;

             case _TRANSACTION_REGISTER_USER:
                return new ProcessRegisterUserTransaction;

            case _TRANSACTION_VALIDATE_TEMPORAL_EMAIL:
                return new ProcessValidateTemporalEmailTransaction;

            case _TRANSACTION_VALIDATE_TEMPORAL_USER:
                return new ProcessValidateTemporalUserTransaction;

            case _TRANSACTION_CONFIRM_PAYMENT_METHOD_CONSUMER:
                return new ProcessConfirmPaymentMethodConsumerTransaction;

            case _TRANSACTION_GET_SECURITY_QUESTIONS:
                return new ProcessGetSecurityQuestionsTransaction;

            case _TRANSACTION_GET_SECURITY_QUESTIONS_BY_ID:
                return new ProcessGetSecurityQuestionsByIdTransaction;

             case _TRANSACTION_VALIDATE_ANSWERS_BY_CONSUMER_ID:
                return new ProcessValidateAnswersByConsumerIdTransaction;

            case _TRANSACTION_GET_RANDOM_SECURITY_QUESTIONS_BY_CONSUMER_ID:
                return new ProcessGetRandomSecurityQuestionsByConsumerIdTransaction;

            case _TRANSACTION_GET_REMOTE_ITEMS_TO_RECOMMEND_BY_MERCHANT_ID:
                return new ProcessGetRemoteItemsToRecommendByMerchantIdTransaction;

            case _TRANSACTION_EDIT_RECOMMENDED_ITEMS:
                return new ProcessEditRecommendedItemsTransaction;

            case _TRANSACTION_ADD_LOCATIONS_TO_REMOTE_ITEMS:
                return new ProcessAddLocationsToRemoteItemsTransaction;

            case _TRANSACTION_GET_REMOTE_ITEMS_BY_ID:
                return new ProcessGetRemoteItemsByIdTransaction;

            case _TRANSACTION_GET_BARCODE_LIST:
                return new ProcessGetBarcodeListTransaction;

            case _TRANSACTION_REMOVE_LOYALTY_PROGRAM:
                return new ProcessRemoveLoyaltyProgramTransaction;

            case _TRANSACTION_REMOVE_REMOTE_ITEM:
                return new ProcessRemoveRemoteItemTransaction;

            case _TRANSACTION_GET_LOCATIONS_BY_COUPON_ID:
                return new ProcessGetLocationsByCouponIdTransaction;

            case _TRANSACTION_REGISTER_MERCHANT_THREE:
                return new ProcessRegisterMerchant3Transaction;

			case _TRANSACTION_GET_INVOICES_CONSUMER_BY_TRANSACTION_ID:
                return new ProcessGetInvoicesConsumerByTransactionIdTransaction;

			case _TRANSACTION_GET_MESSAGE_COUNT_BY_INVOICE_ID:
                return new ProcessGetMessageCountByInvoiceIdTransaction;

			case _TRANSACTION_GET_CONSUMER_BY_PINCODE:
                return new ProcessGetConsumerByPincodeTransaction;

            case _TRANSACTION_GET_FIRST_USER:
                return new ProcessGetFirstUserTransaction;

            case _TRANSACTION_EDIT_TEMPORAL_PASSWORD_BY_CONSUMER_ID:
                return new ProcessEditTemporalPasswordByConsumerIdTransaction;

            case _TRANSACTION_GET_MESSAGE_BY_CONSUMER_ID:
                return new ProcessGetMessageByConsumerIdTransaction;

            case _TRANSACTION_FORGOT_PASSWORD_MERCHANT:
                return new ProcessForgotPasswordMerchantTransaction;

            case _TRANSACTION_EDIT_TEMPORAL_PASSWORD_BY_MERCHANT_ID:
                return new ProcessEditPasswordTemporalByMerchantIdTransaction;

            case _TRANSACTION_ADD_SHIPPING_STATUS_TO_TRANSACTION:
                return new ProcessAddShippingStatusToTransactionTransaction;

             case _TRANSACTION_GET_INVOICE_DETAILS_BY_CONSUMER_ID:
                return new ProcessGetInvoiceDetailsByConsumerIdTransaction;

            case _TRANSACTION_GET_CONSUMER_REMOTE_BY_FAVORITE_CATEGORY:
                return new ProcessGetConsumerRemoteByFavoriteCategoryTransaction;

            case _TRANSACTION_GET_CONSUMER_FAVORITE_REMOTE:
                return new ProcessGetConsumerFavoriteRemoteTransaction;

            case _TRANSACTION_ADD_FAVORITE_REMOTE:
                return new ProcessAddFavoriteRemoteTransaction;

            case _TRANSACTION_REMOVE_FAVORITE_REMOTE:
                return new ProcessRemoveFavoriteRemoteTransaction;

            case _TRANSACTION_GET_CONSUMER_COUPONS_BY_FAVORITE_CATEGORY:
                return new ProcessGetConsumerCouponsByFavoriteCategoryTransaction;

            case _TRANSACTION_ADD_FAVORITE_CATALOG:
                return new ProcessAddFavoriteCatalogTransaction;

            case _TRANSACTION_REMOVE_FAVORITE_CATALOG:
                return new ProcessRemoveFavoriteCatalogTransaction;

            case _TRANSACTION_GET_FAVORITE_CATALOG:
                return new ProcessGetFavoriteCatalogTransaction;

            case _TRANSACTION_GET_REMOTE_ITEMS_BY_CATALOG_ID_PORTAL:
                return new ProcessGetRemoteItemsByCatalogIdPortalTransaction;

            case _TRANSACTION_ADD_FAVORITE_COUPON:
                return new ProcessAddFavoriteCouponTransaction;

            case _TRANSACTION_REMOVE_FAVORITE_COUPON:
                return new ProcessRemoveFavoriteCouponTransaction;

            case _TRANSACTION_GET_CONSUMER_FAVORITE_CLUB:
                return new ProcessGetConsumerFavoriteClubsTransaction;

            case _TRANSACTION_GET_CONSUMER_FAVORITE_COUPONS:
                return new ProcessGetConsumerFavoriteCouponsTransaction;

            case _TRANSACTION_REMOVE_SELECT_COUPON:
                return new ProcessRemoveSelectCouponTransaction;

            case _TRANSACTION_REMOVE_SELECT_REMOTE:
                return new ProcessRemoveSelectRemoteTransaction;

        default:
            return new ProcessDefaultTransaction;
    }

}



/*
 * Class:     InterfaceJava
 * Method:    QRCode
 *	jobjectArray Fields		: fields
 */
JNIEXPORT jcharArray JNICALL Java_InterfaceJavaISO_NMC_BuildIsoMessage
  (JNIEnv *env, jobject obj, jobjectArray Fields , jint trancsation)
{

#ifdef logbegin
    logbegin;
#endif

    NMCLog::Log("---------------------BEGIN TRANSACTION---------------------");

	try
	{
		int SizeArray=env->GetArrayLength( Fields);

#ifdef logbasic
		logbasic<<"Num. Fields: ["<<SizeArray<<"]"<<endl;
#endif



        NMCLog::Log(string("Transaction: [") + tools::itoa((int)trancsation) + string("] Num. Fields: [") + tools::itoa((int)SizeArray) + string("]"));

		hasresult hData;


		//get all fields
		for(int i=0 ; i<SizeArray ; i++)
		{
		    NMCLog::Log(tools::itoa(i));
			jobjectArray Key_Field= (jobjectArray)env->GetObjectArrayElement(Fields, i);
            NMCLog::Log("Get Object Array OK");
			jstring jField = (jstring) env->GetObjectArrayElement( Key_Field, 0);
			NMCLog::Log("Get Field OK");
			jstring jData = (jstring) env->GetObjectArrayElement( Key_Field, 1);
			NMCLog::Log("Get Data OK");
			string Field(env->GetStringUTFChars( jField, 0));
			NMCLog::Log(Field);
			string Data=string(env->GetStringUTFChars( jData, 0));
            NMCLog::Log(Data);
#ifdef logbasic
			logbasic<<"Field: ["<<Field	<<"] Data ["<<Data<<"]"<<endl;
#endif
            NMCLog::Log(string("Field: [") + Field + string("] Data [") + Data + string("]"));

			hData[Field]=Data;
		}


        CoreTransaction *ProccessTransaction;

        ProccessTransaction = (CoreTransaction *)ChooseTransactionClass(trancsation);

        bool log = false;
        string nameTransaction="";
        string dataLog="";

        string Response = ProccessTransaction->Transaction(hData,log,nameTransaction,dataLog);

        //send log
        if(log)
        {
            NMCLog::Log("---------------------LOG---------------------");

            if(Response=="" || Response.length()==0)
            {
                dataLog = string("{Failed Comunications} - ") + dataLog;
            }
            else if(Response[0]!='{' && Response[0]!='[')
            {
                dataLog = string("{") + Response + string("} - ") + dataLog;
            }
            else
            {
                if(Response.compare("{true}")==0 || Response.compare("{false}")==0)
                {
                    dataLog = Response + string(" - ") + dataLog;
                }
                else
                {
                    dataLog = string("{OK} - ") + dataLog;
                }
            }

            ProcessAddLogTransaction *logs;
            logs = new ProcessAddLogTransaction;

            hData.clear();

            hData[__logName]=nameTransaction;
            if(dataLog.length()>254)
                hData[__description]=dataLog.substr(0,254);
            else
                hData[__description]=dataLog;

            logs->Transaction(hData,log,nameTransaction,dataLog);

            NMCLog::Log("---------------------END LOG---------------------");

            delete logs;
        }

        if(Response=="")
        {
            NMCLog::Log("Failed [Comunications]");
            NMCLog::Log("---------------------END TRANSACTION---------------------");
            return NULL;
        }

		int SizeDataOut=Response.length();

        delete ProccessTransaction;

        jcharArray CharReturn = env->NewCharArray(SizeDataOut);

        //
        if(CharReturn == NULL)
        {
            NMCLog::Log("Failed [Invalid Response]");
            NMCLog::Log("---------------------END TRANSACTION---------------------");
            return NULL;
        }

        NMCLog::Log(Response);

        jchar AuxArray[SizeDataOut];
        char StringOut[SizeDataOut];

        memset(AuxArray,0,sizeof(AuxArray));
        memset(StringOut,0,sizeof(StringOut));

        memcpy(StringOut,Response.c_str(),SizeDataOut);

#ifdef logbasic
        logbasic<<"Begin Build Array Out"<<endl;
#endif

        for(int i=0 ; i<SizeDataOut ; i++)
        {
            AuxArray[i] = (jchar)StringOut[i];
#ifdef heavylog
			heavylog<<"Byte ["<<i+1<<"] ["<<StringOut[i]<<"] ["<<AuxArray[i]<<"]"<<endl;
#endif
        }

#ifdef logbasic
        logbasic<<"End Build Array Out"<<endl;
#endif

        env->SetCharArrayRegion(CharReturn, 0,SizeDataOut,AuxArray);

        NMCLog::Log("---------------------END TRANSACTION---------------------");

        return CharReturn;
	}
	catch(...)
	{
	    NMCLog::Log("---------------------END TRANSACTION---------------------");
		return NULL;
	}
}



string InterfaceJavaISO_NMC_BuildIsoMessage (string Fields[][2] , int size , int trancsation)
{
    NMCLog::Log("---------------------BEGIN TRANSACTION---------------------");

    try
    {

        NMCLog::Log(string("Transaction: [") + tools::itoa(trancsation) + string("] Num. Fields: [") + tools::itoa(size) + string("]"));

		hasresult hData;


		//get all fields
		for(int i=0 ; i<size ; i++)
		{
#ifdef logbasic
			logbasic<<"Field: ["<<Fields[i][0]	<<"] Data ["<<Fields[i][1]<<"]"<<endl;
#endif

            NMCLog::Log(string("Field: [") + Fields[i][0] + string("] Data [") + Fields[i][1] + string("]"));
			hData[Fields[i][0]]=Fields[i][1];
		}

#ifdef logbasic
		logbasic<<"Instance Transaction"<<endl;
#endif
        CoreTransaction *ProccessTransaction;

#ifdef logbasic
		logbasic<<"Get Transaction"<<endl;
#endif

        ProccessTransaction = (CoreTransaction *)ChooseTransactionClass(trancsation);

#ifdef logbasic
		logbasic<<"Get Response"<<endl;
#endif
        bool log = false;
        string nameTransaction;
        string dataLog;
        string Response = ProccessTransaction->Transaction(hData,log,nameTransaction,dataLog);

        //send log
        if(log)
        {
            NMCLog::Log("---------------------LOG---------------------");

            if(Response=="" || Response.length()==0)
            {
                dataLog = string("{Failed Comunications} - ") + dataLog;
            }
            else if(Response[0]!='{' && Response[0]!='[')
            {
                dataLog = string("{") + Response + string("} - ") + dataLog;
            }
            else
            {
                if(Response.compare("{true}")==0 || Response.compare("{false}")==0)
                {
                    dataLog = Response + string(" - ") + dataLog;
                }
                else
                {
                    dataLog = string("{OK} - ") + dataLog;
                }
            }

            ProcessAddLogTransaction *logs;
            logs = new ProcessAddLogTransaction;

            hData.clear();

            hData[__logName]=nameTransaction;
            if(dataLog.length()>254)
                hData[__description]=dataLog.substr(0,254);
            else
                hData[__description]=dataLog;

            logs->Transaction(hData,log,nameTransaction,dataLog);

            NMCLog::Log("---------------------END LOG---------------------");

            delete logs;
        }

        if(Response=="")
        {
            NMCLog::Log("Failed [Comunications]");
            NMCLog::Log("---------------------END TRANSACTION---------------------");
            return NULL;
        }
        NMCLog::Log(Response);
#ifdef logbasic
		logbasic<<"Response -- "<<Response<<endl;
#endif

        NMCLog::Log("---------------------END TRANSACTION---------------------");
        return Response;
    }
    catch(...)
    {
        return "Error";
    }
}
