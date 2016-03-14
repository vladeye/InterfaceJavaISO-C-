#ifdef __nmc_json

#ifndef BUILDJSON_H
#define BUILDJSON_H

#include <string>

#include "json_spirit.h"
#include <cassert>
#include <fstream>

#ifndef JSON_SPIRIT_VALUE_ENABLED
#error Please define JSON_SPIRIT_VALUE_ENABLED for the Value type to be enabled
#endif

using namespace std;
using namespace json_spirit;



struct ShippingOption
{
    long id;
	string name;
	string type; // TODO what are the types??
	string terms;
	double cost;
	bool taxable;
	double taxes;
};

struct Address
{
    string addressLine1;
	string addressline2;
	string country;
	string state;
	string city;
	string zipCode;
	string type;
	bool mainAddress;
};

struct Terminal
{
    long id;
    string name;
	string details;
};

struct Location
{
    int numTerminal;
    Terminal *terminals;

	double latitude;
	double longitude;

    Address address;
};

struct Category
{
    long id;
    string name;
    //Category category;
};

struct RemoteItem
{
    long id;
	double price;
	bool taxable;
	double taxes;
	string name;
	string description;
	string termsAndConditions;
	string upcCode;
	string skuCode;
	string image; // TODO where will the image be??
	string option1Name;
	string option2Name;
	string option1;
	string option2; // TODO what the option is?
	string barcodeImage;
	string qrCodeImage;

	Category category;

	int numShippingOption;
	ShippingOption *shippingOptions;
};

struct LoyaltyProgram
{
    string atclass;

    long id;
    double originalPrice;
    double salePrice;
    bool recurringCharge;
    double recurringChargeAmount;
    string dateCreated;
    string dateActive;
    string dateExpire;
    string name;
    string termsAndConditios;
    string barcodeImage;
    string upcCode;
    string brand;
    string image;

    Category category;

    string recurringChargesCurrency;

    int numLocation;
    Location *location;

    int numRemoteItem;
    RemoteItem *remoteitem;
};

struct Permissions
{
    string permissionName;
    bool canEdit;
    bool canDelete;
    bool canRead;
    bool canAdd;
};

struct UserGroup
{
    string groupName;
    int numPermissions;
    Permissions *permissions;
    int groupId;
};

struct PaymentMethod
{
    string atclass;

    int id;
    string responsible;
    string type;
};

struct Country
{
    bool available;
	string code;
	string name;
	string shortName;
};

struct Phones
{
    string phoneNumber;
    Country country;
    string type;
};

struct User
{
    string atclass;

    bool isAvailable;
    int id;
    string companyName;
    string nickName;
    string firstName;
    string lastName;
    string middleName;
    string email;
    string country;
    string type;

    int numGroups;
    UserGroup *usergroup;

    int numPaymentMethod;
    PaymentMethod *paymentmethod;

    int numPhones;
    Phones *phones;

    int numPermissions;
    Permissions *permissions;
};

struct AppSettings
{
    string atclass;

    string language;
    int screenLockMinutes;
    int screenLockSeconds;
};

struct Suscription
{
    long id;
	string name;
	double cost;
	int duration;
	string durationType;
	string purchaseDate;
	bool autoRenew;
};

struct Merchant
{
    string assignedTo;
	string supervisor;
	string department;
    Category category;
	AppSettings appSettings;

	int numSuscription;
	Suscription *suscriptions;

	int numLocation;
	Location *locations;
    User user;
};

struct LoyaltySettings
{
    int numCategory;
    Category *category;

    int numMerchant;
    User *merchant;

    int numAddress;
    Address *address;

    bool recievePushNotifications;
    bool whenPromotionExpiresTomrrow;
    bool onlyNewPromotionFromFavorites;
    bool autodeleteUsedExpiredFromFavorites;
    string receiveNotificationUntil;
    string receiveNotificationFrom;
};

struct NoMoreCardsSession
{
    User user;

    AppSettings appSettings;

    LoyaltySettings loyaltySettings;

};

struct Ticket
{
    bool isClosed;
    long id;
    string subject;
    string assignedTo;
    string name;
    string dateOpen;
    string resolved;
    string type;
    string status;
    string dateCreated;
    string lastActivity;
    User owner;

    int numNotes;
    string *notes;
};

struct Consumer
{
    string title;
    string birthDate;
    Address mainaddress;
    AppSettings appsettings;
    LoyaltySettings loyaltysettings;

    int numAddress;
    Address *address;

    User user;
};

struct InvoiceItem
{
    int quantity;
    double totalCost;
};

struct Account
{
    long id;
    long invoiceNumber;
    double ammount;
    string companyName;
    string dateIssued;
    string dateDue;
    string type;
    string priority;

    Consumer consumer;
    int numInvoiceItem;
    InvoiceItem *invoiceitem;
};

struct AdminAppSettings
{
    bool pushNotification;
    bool mute;
    bool vibrate;
    bool refund;
    bool systemAlerts;
    bool reminders;
    int scanTimeout;
    bool expandGiftCard;

    AppSettings appSettings;
};

struct ConsumerCreditCard
{
    int cvv;
    long id;
    string holderName;
    string pan;
    string expirationDate;
    string PaymentMethodType;
};

struct ClubMembership
{
    LoyaltyProgram loyaltyProgram;
    string logoImage;
    bool needsFaces;
    int numFaceImages;
    string *faceimages;
};

struct Coupon
{
    LoyaltyProgram loyaltyProgram;
};

struct Invoice
{
    long id;
    string transactionId;
    string transactionType;
    string transactionDate;
    Merchant merchant;
    Consumer consumer;
    Address address;
    double totalAmount;
    double itemsAmount;
    double savingAmount;
    PaymentMethod paymentmethod;

    int numInvoiceItem;
    InvoiceItem *invoiceitem;
};

struct MerchantAppSettings
{
    AppSettings appSettings;
};

struct Rating
{
    long id;
    int rate;
    User rater;
    User rated;
    string rateDate;
};

struct Reseller
{
    string assignedTo;
    string supervisor;
    string department;
    AppSettings appsettings;
    int numSuscription;
    Suscription *suscription;
    int numLocation;
    Location *location;
    int numMerchant;
    Merchant *merchant;

    User user;
};

struct ResellerAppSettings
{
    AppSettings appsettings;
};

struct SellerPaymentMethod
{
    long id;
    string issuer;
    string merchantId;
    string type;
};


struct WishList
{
    long id;
	string name;
	string dateCreated;
	Category category;
	int numWishes;
	LoyaltyProgram wishes;
};


class buildJson
{
    public:
        buildJson();
        bool buildJsonUser(User *nom, int numUser,  Object &objectOut, Value &valueOut);
        bool buildJsonNoMoreCardsSession(NoMoreCardsSession *nom,const int NumSession,Object &obj,Value &valOut);
        bool buildJsonAppSettings(AppSettings *nom,int numAppSettings,Object &obj,Value &val);
        bool buildJsonLoyaltySettings(LoyaltySettings *nom,int numLoyaltySettings,Object &obj,Value &val);
        bool buildJsonCategories(Category *nom,int numCategory,Object &obj,Value &val);
        bool buildJsonMerchant(Merchant *nom,int numMerchant,Object &obj,Value &val);
        bool buildJsonAddress(Address *nom, int numAddress,  Object &objectOut, Value &valueOut);
        bool buildJsonSuscription(Suscription *nom, int numSuscription,  Object &objectOut, Value &valueOut);
        bool buildJsonLocation(Location *nom, int numLocation,  Object &objectOut, Value &valueOut);
        bool buildJsonRemoteItems(RemoteItem *nom, int numRemoteItems,  Object &objectOut, Value &valueOut);
        bool buildJsonShippingOption(ShippingOption *nom, int numShippingOption,  Object &objectOut, Value &valueOut);
        bool buildJsonUserGroup (UserGroup *nom, int numGroups,  Object &objUserGroup, Value &valUserGroup);
        bool buildJsonPaymentMethod(PaymentMethod *nom, int numPaymentMethod,  Object &objPaymentMethod, Value &valPaymentMethod);
        bool buildJsonPhones(Phones *nom, int numPhones,  Object &objPhones, Value &valPhones);
        bool buildJsonPermissions(Permissions *nom, int numPermissions,  Object &objPermissions, Value &valPermissions);
        bool buildJsonTicket(Ticket *tick, int numTicket,  Object &objectOut, Value &valueOut);
        bool buildJsonTerminal(Terminal *nom, int numTerminal,  Object &objectOut, Value &valueOut);

        bool buildJsonConsumer(Consumer *nom, int numConsumer,  Object &objectOut, Value &valueOut);
        bool buildJsonAccount(Account *nom, int numAccount,  Object &objectOut, Value &valueOut);
        bool buildJsonAdminAppSettings(AdminAppSettings *nom, int numAdminAppSettings,  Object &objectOut, Value &valueOut);
        bool buildJsonConsumerCreditCard(ConsumerCreditCard *nom, int numConsumerCreditCard,  Object &objectOut, Value &valueOut);
        bool buildJsonClubMembership(ClubMembership *nom, int numClubMembership,  Object &objectOut, Value &valueOut);
        bool buildJsonCoupon(Coupon *nom, int numCoupon,  Object &objectOut, Value &valueOut);
        bool buildJsonInvoice(Invoice *nom, int numInvoice,  Object &objectOut, Value &valueOut);
        bool buildJsonInvoiceItem(InvoiceItem *nom, int numInvoiceItem,  Object &objectOut, Value &valueOut);
        bool buildJsonLoyaltyProgram(LoyaltyProgram *nom, int numLoyaltyProgram,  Object &objectOut, Value &valueOut);
        bool buildJsonMerchantAppSettings(MerchantAppSettings *nom, int numMerchantAppSettings,  Object &objectOut, Value &valueOut);
        bool buildJsonRating(Rating *nom, int numRating,  Object &objectOut, Value &valueOut);
        bool buildJsonReseller(Reseller *nom, int numReseller,  Object &objectOut, Value &valueOut);
        bool buildJsonResellerAppSettings(ResellerAppSettings *nom, int numResellerAppSettings,  Object &objectOut, Value &valueOut);
        bool buildJsonSellerPaymentMethod(SellerPaymentMethod *nom, int numSellerPaymentMethod,  Object &objectOut, Value &valueOut);
        bool buildJsonFaceImages(string *nom, int numFaceImages,  Object &objectOut, Value &valueOut);
        bool buildJsonNotes(string *nom, int numNotes,  Object &objectOut, Value &valueOut);
        bool buildJsonCountry(Country *nom, int numCountry,  Object &objectOut, Value &valueOut);

        virtual ~buildJson();
};

#endif // BUILDJSON_H

#endif
