#include "CoreTransaction.h"

#ifndef __BUILD_TRANSACTIONS_H__
#define __BUILD_TRANSACTIONS_H__

//if the transaction is invalid
class ProcessDefaultTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateUserTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetUserSettingsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetUserActivityTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerByEmailAndStatusTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoicesByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPayableAccountsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetReceivableAccountsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPayableAccountsByTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetReceivableAccountsByTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCategoriesTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessCreateCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessCreateSubcategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSubcategoriesTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveSubcategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditSubcategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddAditionalCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditAditionalCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessDeleteAditionalCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTicketsByConsumerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSecurityTicketsByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantLoyaltyProgramsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerClubsAndMembershipsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantClubsAndMembershipsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerLoyaltyProgramsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCustomerRatingsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerRatingsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRatingsByUserIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetNotesByUserIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantRatingsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetUsersMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetUsersConsumerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetUsersResellerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerByIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantByIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerByIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddConsumerWishListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveConsumerWishListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRecentInvoicesTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessLoyaltyProgramsListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessLoyaltyProgramsFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessLoyaltyAddNewLoyalityProgramsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoteItemsListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoteItemsFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoteItemsAddNewLoyaltyProgramTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessHistoryListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessHistoryFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRatingsAndReviewsListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRatingsAndReviewsFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMailConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessChangePaswordConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessChangePaswordMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessChangePaswordResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessUserManagementTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessPaymentDataTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditLocationsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileAddLocationsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessDisableLocationsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditPermisionsConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditPermisionsMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditPermisionsResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileAddNewConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileRemoveUserConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileRemoveUserMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileRemoveUserResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessViewBillingHistyoryListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessExistingSubscriptionsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddOnsForExistingSubscriptionsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessNewSubsicriptionsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMailMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMailResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerWishListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddFavoriteAddressTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveFavoriteAddressTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileAddNewMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddLoyaltyProgramsToWishListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveLoyaltyProgramsToWishListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileAddNewResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddFavoriteCategoryTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveFavoriteCategoryTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetFavoriteCategoryTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddFavoriteMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveFavoriteMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetFavoriteMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetFavoriteAddressTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateEmailTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateCompannyNameTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetClubsAndMembershipsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerInvoicesTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantByEmailAndStatusTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRecentInvoicesTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerByEmailAndStatusTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoicesByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoicesByResellerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSecurityTicketsByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSecurityTicketsByResellerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTicketsByMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTicketsByResellerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessLostPhoneTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerCouponAndPromotionsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewRatingsAndReviewsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCountriesTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCategoryByIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetStatesByCountryCodeTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSubCategoriesByParentIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerByTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantByTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerByTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoicesByDateTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchUserConsumerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchUserMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchUserResellerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAdminNewConsumerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAdminNewMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAdminNewResellerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewCouponTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewPromotionTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRegisterMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddMerchantAccountNameTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddStoreMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRegisterConsumerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCouponTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPromotionTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCouponByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPromotionByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetClubsAndMembershipsByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewClubAndMembershipTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddLogTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLogsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantCouponFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantPromotionFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMerchantClubsAndMembershipsFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerCouponFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerPromotionFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerClubsAndMembershipsFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddLocationToLoyaltyProgramTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveLocationToLoyaltyProgramTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLoyaltyProgramsByLocationIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddRemoteItemsToLoyaltyProgramTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveRemoteItemsToLoyaltyProgramTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemsByLoyaltyProgramsIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddShoppingListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveShoppingListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddItemsToShoppingListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveItemsToShoppingListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditShoppingListNameTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetShoppingListByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLoyaltyProgramsByRemoteItemIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetNameShoppingListByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetShoppingRemoteItemsFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetShoppingLoyaltyProgramsFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemsByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewRemoteItemTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetShoppingListNameTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCreditCardByConsumerIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessTotalSalesPerDayTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewShippingOptionsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetShippingOptionTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditShippingOptionsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveShippingOptionsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCouponByIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetClubsAndMembershipsByIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPromotionByIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessIsFavoriteMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoicesConsumerFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessMoveItemBetweenShoppingListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRatingsAndReviewsByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerRatingsandReviewsFilterTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCouponToExpireByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetAddressByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessChangePasscodeTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditLanguageAndLockTimeTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLastCouponCreatedByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRegisterUserMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRatingsandReviewsbyIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessReplayRatingsAndReviewsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessReportToNMCTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRecentMessageSystemByMerchantIDTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewHelpTicketsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetHelpTicketsByIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTicketsByParentIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewActionTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoicesByDateAndMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetListResellerCompanyNameTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRatingsandReviewsbyParentIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCategoryOfBusinessListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSubcategoryOfBusinessByParentIdListTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateRartingAndReviewIsReportedToNMCTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewMerchantPermissionLoyaltyTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewMerchantPermissionRemoteTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewMerchantPermissionAccountingTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewMerchantPermissionTransactionsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewMerchantPermissionSubscriptionsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewMerchantPermissionReviewsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewMerchantPermissionUsersTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPermissionTransactionsByMerchantIDTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPermissionSubscriptionsByMerchantIDTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPermissionReviewsByMerchantIDTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPermissionLoyaltyByMerchantIDTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPermissionAccountingByMerchantIDTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPermissionRemoteByMerchantIDTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPermissionUserByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetImagesByLoyaltyIDTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLoyaltyProgramsByUserMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCategoryByParentIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCategoryByTypeTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTypesOfCategoriesTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLocationsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddImagesToLoyaltyProgramsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddlocationsToLoyaltyProgramsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCountryCurrencyCodeTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddImagesToRemoteItemsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCompanyNameByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewCatalogTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetChoicesByOptionIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetOptionsByRemoteIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTotalByOptionIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewChoiceTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewOptionTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddTotalByOptionIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCatalogsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCitiesByStateIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessRemoveCatalogTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessMoveToCatalogTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveItemsFromCatalogTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessGetRemoteItemsByCatalogIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMessageByInvoiceIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMessageByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTransactionsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewInvoiceMessageTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewInvoiceNoteTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSeqImagesNameTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessGetInvoiceDetailsCatalogByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoiceDetailsLoyaltyByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessGetInvoiceDetailsRemoteItemsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetNotesByInvoiceIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessUpdateShippingStatusTransactionTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTerminalsByLocationIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileGetMerchantByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewTerminalTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessDeleteCreditCardMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessDeleteTerminalsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessEnableLocationsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCreditCardByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetBillingHistoryMerchantByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInactiveLocationsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSetFavoriteCreditCardMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPaymentMethodByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTypeOfBusinessByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileAddPaymentMethodTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileRemovePaymentMethodTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessProfileEditUserMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetUsersMerchantByParentIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewContactUsMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetHelpTicketsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSuspendUsersMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessDeleteLoyaltyProgramByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessDeleteRemoteItemByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditLoyaltyProgramsByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditRemoteItemByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetBillingHistoryListMerchantByMerchantIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetHelpTticketsByMerchantIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchHelpTticketsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchLoyaltyProgramsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMerchantPermissionAccountingTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMerchantPermissionLoyaltyTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMerchantPermissionRemoteTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMerchantPermissionReviewsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMerchantPermissionSubscriptionsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMerchantPermissionTransactionsTransactions: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditMerchantPermissionUsersTransactions: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCatalogLoyaltyRemoteByMerchantIdForAddTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemsByMerchantIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchRemoteItemsByCatalogIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchRemoteItemsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemsByCatalogIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchUsersMerchantByParentIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetUsersMerchantByParentIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchMerchantRatingsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessGetMerchantRatingsFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAcceptNewTransactionTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewProductTransactionTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewTemporalTransactionTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddRefundByTransactionProductIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTransactionsByMerchantIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchTransactionsByMerchantIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessConfirmMerchantPasswordTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTransactionByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetHelpTicketsByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRecentInvoicesByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchInvoicesByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditTerminalTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTransactionsByCardTockenTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchTransactionsByCardTockenTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTransactionsByCardTockenFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewCreditCardMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessCounterAccountsByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetClubAndMembershipByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetClubAndMembershipByConsumerIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetClubAndMembershipByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetClubAndMembershipInShoppingListByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};





class ProcessGetConsumerCouponFilterByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerCouponTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetStatusFacebookTwitterByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};




class ProcessGetConsumerPromotionFilterByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerPromotionsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerRemoteItemTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetCouponByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};



class ProcessGetExpiringInSevenDaysClubAndMembershipByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetJoinedClubAndMembershipByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetJoinNowClubAndMembershipByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetPromotionsByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchConsumerCouponAndPromotionTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchConsumerCouponAndPromotionByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchGetClubAndMembershipByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchRemoteItemByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerClubAndMembershipFilterByShoppingListIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessSaveSecretQuestionByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddPaymentAccountConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessEditPaymentAccountConsumerByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddImagesToProductByConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateConsumerPasswordTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessValidateConsumerPincodeTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemovePaymentAccountConsumerByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSaleItemsByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchSaleItemsByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSaleItemsByConsumerIdFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewConsumerAddressTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSetDefaultConsumerAddressTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditConsumerAddressTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveConsumerAddressByIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerAddressByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewOptionConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddTotalByOptionIdConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSetStatusFacebookTwitterByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLanguageScreenLockTimeByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSetLanguageScreenLockTimeByConsumerIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessChangeMailConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessContactNMCConsumerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewSaleItemTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessEditSaleItemTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveSaleItemTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSaveStatusLostPhoneTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerNotificationSettingsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditConsumerNotificationSettingsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessDeleteUserMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditCreditCardMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessContactNMCResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessGetResellerRatingsAndReviewsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchResellerRatingsAndReviewsTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerRatingsFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerHelpTicketsfromMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerHelpTicketsfromMerchantFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerHelpTicketsToAdminTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellerHelpTicketsToAdminFilterTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchResellerHelpTicketsFromMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessSearchResellerHelpTicketsToAdminTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewHelpTicketsResellerTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetResellersTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetImagesByRemoteItemIdTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditManagementUserMerchantTransaction: public CoreTransaction
{
    public :
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSupervisorMerchantByParentIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessGetPathByNameTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditPathTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewPathTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessValidateNamePathTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTerminalByIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetZipCodeByCityTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRegisterTemporalUserTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddNewPinCodeTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessForgotPasswordConsumerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetTemporalUserTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessRegisterUserTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateTemporalEmailTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateTemporalUserTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessConfirmPaymentMethodConsumerTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSecurityQuestionsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetSecurityQuestionsByIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessValidateAnswersByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


class ProcessGetRandomSecurityQuestionsByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemsToRecommendByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditRecommendedItemsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddLocationsToRemoteItemsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemsByIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetBarcodeListTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveLoyaltyProgramTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveRemoteItemTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetLocationsByCouponIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRegisterMerchant3Transaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoicesConsumerByTransactionIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMessageCountByInvoiceIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerByPincodeTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetFirstUserTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditTemporalPasswordByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetMessageByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessForgotPasswordMerchantTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessEditPasswordTemporalByMerchantIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddShippingStatusToTransactionTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetInvoiceDetailsByConsumerIdTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerRemoteByFavoriteCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerFavoriteRemoteTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddFavoriteRemoteTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveFavoriteRemoteTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerCouponsByFavoriteCategoryTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddFavoriteCatalogTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveFavoriteCatalogTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetFavoriteCatalogTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetRemoteItemsByCatalogIdPortalTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessAddFavoriteCouponTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveFavoriteCouponTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerFavoriteClubsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessGetConsumerFavoriteCouponsTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveSelectCouponTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};

class ProcessRemoveSelectRemoteTransaction : public CoreTransaction
{
    public:
        string Transaction(hasresult &hData,bool &log,string &nameTransaction,string &dataLog);
};


#endif
