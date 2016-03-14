#ifdef __nmc_json

#include "buildJson.h"

//logs
//#define logbegin	cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- Begin"<<endl
//#define logend      cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- End"<<endl
//#define heavylog	cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- "
//#define logbasic	cout<<"["<<__FUNCTION__<<"] ["<<__LINE__<<"] -- "
//#define __DEBUG_DATA_2_SEND

#if defined(logbegin) || defined (logend) || defined (logbasic) || defined (__DEBUG_DATA_2_SEND) || defined (heavylog)
    #include <iostream>
#endif

buildJson::buildJson(){}
buildJson::~buildJson(){}

bool buildJson::buildJsonUser(User *nom, int numUser, Object &objectOut, Value &valueOut)
{
    Object objTemp;
    Value valUser;

    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numUser==0)?1:numUser); i++)
    {

        addr_obj1.push_back( Pair( "@class", nom[i].atclass ) );
        addr_obj1.push_back( Pair( "available", nom[i].isAvailable ) );
        addr_obj1.push_back( Pair( "id", nom[i].id ) );
        addr_obj1.push_back( Pair( "companyName", nom[i].companyName ) );
        addr_obj1.push_back( Pair( "nickName", nom[i].nickName ) );
        addr_obj1.push_back( Pair( "firstName", nom[i].firstName ) );
        addr_obj1.push_back( Pair( "lastName", nom[i].lastName ) );
        addr_obj1.push_back( Pair( "middleName", nom[i].middleName ) );
        addr_obj1.push_back( Pair( "email", nom[i].email ) );
        addr_obj1.push_back( Pair( "country", nom[i].country ) );
        addr_obj1.push_back( Pair( "type", nom[i].type ) );

        this->buildJsonUserGroup(nom[i].usergroup, nom[i].numGroups, objTemp, valUser);
        addr_obj1.push_back( Pair( "groups", valUser ));

        this->buildJsonPaymentMethod(nom[i].paymentmethod,nom[i].numPaymentMethod, objTemp, valUser);
        addr_obj1.push_back(Pair( "paymentMethods", valUser ));

        this->buildJsonPhones(nom[i].phones,nom[i].numPhones, objTemp,valUser);
        addr_obj1.push_back(Pair( "phones", valUser ));

        this->buildJsonPermissions(nom[i].permissions,nom[i].numPermissions, objTemp,valUser);
        addr_obj1.push_back(Pair( "permissions", valUser ));

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numUser==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonNoMoreCardsSession(NoMoreCardsSession *nom,const int NumSession,Object &obj,Value &valOut)
{
    Object objNoMoreCardsSession;
    Object objNMCS;


    Value tempVal;
    vector< Object > vecNoMoreCardsSession;

    for(int i=0;i<((NumSession==0)?1:NumSession);i++)
    {

        //generate user
        this->buildJsonUser(&nom[i].user,0,objNMCS,tempVal);
        objNoMoreCardsSession.push_back(Pair( "loggerUser", objNMCS));
        objNMCS.clear();

        //app settings
        this->buildJsonAppSettings(&nom[i].appSettings,0,objNMCS,tempVal);
        objNoMoreCardsSession.push_back(Pair( "settings", objNMCS ));
        objNMCS.clear();

        //loyalty settings
        this->buildJsonLoyaltySettings(&nom[i].loyaltySettings,0,objNMCS,tempVal);
        objNoMoreCardsSession.push_back(Pair( "loyaltySettings", objNMCS ));
        objNMCS.clear();

        //build array
        vecNoMoreCardsSession.push_back(objNoMoreCardsSession);
        objNoMoreCardsSession.clear();
    }

    if(NumSession==0)
    {
        obj=vecNoMoreCardsSession[0];

    }
    else
    {
        valOut=Value( vecNoMoreCardsSession.begin(), vecNoMoreCardsSession.end() );

    }

    return true;
}

bool buildJson::buildJsonAppSettings(AppSettings *nom,int numAppSettings,Object &obj,Value &val)
{
    Object objAppSettings;
    vector< Object > vecAppSettings;

    for(int i=0;i<((numAppSettings==0)?1:numAppSettings);i++)
    {
        objAppSettings.push_back(Pair( "@class", nom[i].atclass));

        //language
        objAppSettings.push_back(Pair( "language", nom[i].language ));

        //ScreenLockMinutes
        objAppSettings.push_back(Pair( "screenLockMinutes", nom[i].screenLockMinutes ));

        //ScreenLockSeconds
        objAppSettings.push_back(Pair( "screenLockSeconds", nom[i].screenLockSeconds ));

        //build array
        vecAppSettings.push_back(objAppSettings);
        objAppSettings.clear();
    }

    if(numAppSettings==0)
    {
        obj=vecAppSettings[0];

    }
    else
    {
        val=Value( vecAppSettings.begin(), vecAppSettings.end() );

    }

    return true;
}

bool buildJson::buildJsonLoyaltySettings(LoyaltySettings *nom,int numLoyaltySettings,Object &obj,Value &val)
{
    Object objLoyaltySettings;
    vector< Object > vecLoyaltySettings;

    Object objTemp;
    Value valLytysttings;


    for(int i=0;i<((numLoyaltySettings==0)?1:numLoyaltySettings);i++)
    {


        //favoriteCategories
        this->buildJsonCategories(nom[i].category,nom[i].numCategory,objTemp,valLytysttings);
        objLoyaltySettings.push_back(Pair( "favoriteCategories", valLytysttings ));

        //favoriteMerchants
        this->buildJsonUser(nom[i].merchant,nom[i].numMerchant,objTemp,valLytysttings);
        objLoyaltySettings.push_back(Pair( "favoriteMerchants", valLytysttings ));

        //favoriteAddresses
        this->buildJsonAddress(nom[i].address,nom[i].numAddress,objTemp,valLytysttings);
        objLoyaltySettings.push_back(Pair( "favoriteAddresses", valLytysttings ));

        //recievePushNotifications
        objLoyaltySettings.push_back(Pair( "recievePushNotifications", nom[i].recievePushNotifications ));

        //whenPromotionExpiresTomrrow
        objLoyaltySettings.push_back(Pair( "whenPromotionExpiresTomrrow", nom[i].whenPromotionExpiresTomrrow ));

        //onlyNewPromotionFromFavorites
        objLoyaltySettings.push_back(Pair( "onlyNewPromotionFromFavorites", nom[i].onlyNewPromotionFromFavorites ));

        //autodeleteUsedExpiredFromFavorites
        objLoyaltySettings.push_back(Pair( "autodeleteUsedExpiredFromFavorites", nom[i].autodeleteUsedExpiredFromFavorites ));

        //receiveNotificationUntil
        objLoyaltySettings.push_back(Pair( "receiveNotificationUntil", nom[i].receiveNotificationUntil ));

        //receiveNotificationFrom
        objLoyaltySettings.push_back(Pair( "receiveNotificationFrom", nom[i].receiveNotificationFrom ));

        //build array
        vecLoyaltySettings.push_back(objLoyaltySettings);
        objLoyaltySettings.clear();
    }

    if(numLoyaltySettings==0)
    {
        obj=vecLoyaltySettings[0];

    }
    else
    {
        val=Value( vecLoyaltySettings.begin(), vecLoyaltySettings.end() );

    }

    return true;
}

bool buildJson::buildJsonCategories(Category *nom,int numCategory,Object &obj,Value &val)
{
    Object objCategories;
    vector< Object > vecCategory;

    Object objAux;

    for(int i=0;i<((numCategory==0)?1:numCategory);i++)
    {
        //id
        objCategories.push_back(Pair( "id", (int)nom[i].id ));

        //name
        objCategories.push_back(Pair( "name", nom[i].name ));

        //parent
//        objCategories.push_back(Pair( "parent", objAux ));

        //build array
        vecCategory.push_back(objCategories);
        objCategories.clear();
    }

    if(numCategory==0)
    {
        obj=vecCategory[0];

    }
    else
    {
        val=Value( vecCategory.begin(), vecCategory.end() );

    }

    return true;
}

bool buildJson::buildJsonMerchant(Merchant *nom,int numMerchant,Object &obj,Value &val)
{
    Object objMerchant;
    vector< Object > vecMerchant;


    Value valTemp;
    Object objTemp;


    for(int i=0;i<((numMerchant==0)?1:numMerchant);i++)
    {

        //user
        this->buildJsonUser(&nom[i].user,0,objMerchant,valTemp);

        //assignedTo
        objMerchant.push_back(Pair( "assignedTo", nom[i].assignedTo ));

        //supervisor
        objMerchant.push_back(Pair( "supervisor", nom[i].supervisor));

        //department
        objMerchant.push_back(Pair( "department", nom[i].department));

        //AppSettings
        this->buildJsonAppSettings(&nom[i].appSettings,0,objTemp,valTemp);
        objMerchant.push_back(Pair( "settings", objTemp));
        objTemp.clear();

        //suscriptions
        this->buildJsonSuscription(nom[i].suscriptions, nom[i].numSuscription,objTemp, valTemp);
        objMerchant.push_back(Pair( "suscriptions", valTemp));

        //locations
        this->buildJsonLocation(nom[i].locations, nom[i].numLocation, objTemp, valTemp);
        objMerchant.push_back(Pair( "locations", valTemp));

        //build array
        vecMerchant.push_back(objMerchant);
        objMerchant.clear();

    }

    if(numMerchant==0)
    {
        obj=vecMerchant[0];

    }
    else
    {
        val=Value( vecMerchant.begin(), vecMerchant.end() );

    }

    return true;
}

bool buildJson::buildJsonAddress(Address *nom, int numAddress, Object &objectOut, Value &valueOut)
{
    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numAddress==0)?1:numAddress); i++)
    {

        addr_obj1.push_back( Pair( "addressLine1", nom[i].addressLine1 ) );
        addr_obj1.push_back( Pair( "addressline2", nom[i].addressline2 ) );
        addr_obj1.push_back( Pair( "country", nom[i].country ) );
        addr_obj1.push_back( Pair( "state", nom[i].state ) );
        addr_obj1.push_back( Pair( "city", nom[i].city ) );
        addr_obj1.push_back( Pair( "zipCode", nom[i].zipCode ) );
        addr_obj1.push_back( Pair( "type", nom[i].type ) );
        addr_obj1.push_back( Pair( "mainAddress", nom[i].mainAddress ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();

    }

    if(numAddress==0)
    {
        objectOut=int_vect1[0];
#
    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonSuscription(Suscription *nom, int numSuscription, Object &objectOut, Value &valueOut)
{
    Object objSuscription;
    vector< Object > vecSuscription;

    Value valTemp;

    for(int i=0;i<((numSuscription==0)?1:numSuscription);i++)
    {
        objSuscription.push_back( Pair( "id", (int)nom[i].id ) );
        objSuscription.push_back( Pair( "name", nom[i].name ) );
        objSuscription.push_back( Pair( "cost", nom[i].cost ) );
        objSuscription.push_back( Pair( "duration", nom[i].duration) );
        objSuscription.push_back( Pair( "durationType", nom[i].durationType) );
        objSuscription.push_back( Pair( "purchaseDate", nom[i].purchaseDate ) );
        objSuscription.push_back( Pair( "autoRenew", nom[i].autoRenew ) );


        //build array
        vecSuscription.push_back(objSuscription);
        objSuscription.clear();
    }

    if(numSuscription==0)
    {
        objectOut=vecSuscription[0];

    }
    else
    {
        valueOut=Value( vecSuscription.begin(), vecSuscription.end() );

    }

    return true;
}

bool buildJson::buildJsonLocation(Location *nom, int numLocation, Object &objectOut, Value &valueOut)
{
    Object objLocation;
    vector< Object > vecLocation;

    Value valTemp;
    Object objTemp;

    for(int i=0;i<((numLocation==0)?1:numLocation);i++)
    {

        //address
        this->buildJsonAddress(&nom[i].address, 0, objLocation, valTemp);

        //terminals
        this->buildJsonTerminal(nom[i].terminals,nom[i].numTerminal, objTemp, valTemp);
        objLocation.push_back(Pair( "terminals", valTemp));

        //latitude
        objLocation.push_back(Pair( "latitude", nom[i].latitude));

        //longitude
        objLocation.push_back(Pair( "longitude", nom[i].longitude));

        //build array
        vecLocation.push_back(objLocation);
        objLocation.clear();
    }

    if(numLocation==0)
    {
        objectOut=vecLocation[0];

    }
    else
    {
        valueOut=Value( vecLocation.begin(), vecLocation.end() );

    }

    return true;
}

bool buildJson::buildJsonRemoteItems(RemoteItem *nom, int numRemoteItems, Object &objectOut, Value &valueOut)
{
    Object objRemoteItems;
    vector< Object > vecRemoteItems;


    Value valTemp;
    Object objTemp;


    for(int i=0;i<((numRemoteItems==0)?1:numRemoteItems);i++)
    {
        //id
        objRemoteItems.push_back(Pair( "id", (int)nom[i].id));

        //price
        objRemoteItems.push_back(Pair( "price", nom[i].price));

        //taxable
        objRemoteItems.push_back(Pair( "taxable", nom[i].taxable));

        //taxes
        objRemoteItems.push_back(Pair( "taxes", nom[i].taxes));

        //name
        objRemoteItems.push_back(Pair( "name", nom[i].name));

        //description
        objRemoteItems.push_back(Pair( "description", nom[i].description));

        //termsAndConditions
        objRemoteItems.push_back(Pair( "termsAndConditions", nom[i].termsAndConditions));

        //upcCode
        objRemoteItems.push_back(Pair( "upcCode", nom[i].upcCode));

        //skuCode
        objRemoteItems.push_back(Pair( "skuCode", nom[i].skuCode));

        //image
        objRemoteItems.push_back(Pair( "image", nom[i].image));

        //option1Name
        objRemoteItems.push_back(Pair( "option1Name", nom[i].option1Name));

        //option2Name
        objRemoteItems.push_back(Pair( "option2Name", nom[i].option2Name));

        //option1
        objRemoteItems.push_back(Pair( "option1", nom[i].option1));

        //option2
        objRemoteItems.push_back(Pair( "option2", nom[i].option2));

        //barcodeImage
        objRemoteItems.push_back(Pair( "barcodeImage", nom[i].barcodeImage));

        //qrCodeImage
        objRemoteItems.push_back(Pair( "qrCodeImage", nom[i].qrCodeImage));

        //category
        this->buildJsonCategories(&nom[i].category,0,objTemp,valTemp);
        objRemoteItems.push_back(Pair( "category", objTemp));
        objTemp.clear();

        //shippingOptions
        this->buildJsonShippingOption(nom[i].shippingOptions, nom[i].numShippingOption, objTemp, valTemp);
        objRemoteItems.push_back(Pair( "shippingOptions", valTemp));

        //build array
        vecRemoteItems.push_back(objRemoteItems);
        objRemoteItems.clear();
    }

    if(numRemoteItems==0)
    {
        objectOut=vecRemoteItems[0];

    }
    else
    {
        valueOut=Value( vecRemoteItems.begin(), vecRemoteItems.end() );

    }

    return true;
}

bool buildJson::buildJsonShippingOption(ShippingOption *nom, int numShippingOption, Object &objectOut, Value &valueOut)
{
    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numShippingOption==0)?1:numShippingOption); i++)
    {
        addr_obj1.push_back( Pair( "id",  (int)nom[i].id ) );
        addr_obj1.push_back( Pair( "name", nom[i].name ) );
        addr_obj1.push_back( Pair( "type", nom[i].type ) );
        addr_obj1.push_back( Pair( "terms", nom[i].terms ) );
        addr_obj1.push_back( Pair( "cost", nom[i].cost ) );
        addr_obj1.push_back( Pair( "taxable", nom[i].taxable ) );
        addr_obj1.push_back( Pair( "taxes", nom[i].taxes ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numShippingOption==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonUserGroup (UserGroup *nom, int numGroups, Object &objUserGroup, Value &valUserGroup)
{
    Object objTemp;
    Value valPermissions;

    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numGroups==0)?1:numGroups); i++)
    {

        addr_obj1.push_back( Pair( "groupName", nom[i].groupName ) );

        this->buildJsonPermissions(nom[i].permissions,nom[i].numPermissions,objTemp, valPermissions);
        addr_obj1.push_back(Pair( "groupPermissions", valPermissions ));

        addr_obj1.push_back( Pair( "groupId", nom[i].groupId ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numGroups==0)
    {
        objUserGroup=int_vect1[0];

    }
    else
    {
        valUserGroup= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonPaymentMethod(PaymentMethod *nom, int numPaymentMethod, Object &objPaymentMethod, Value &valPaymentMethod)
{
        Value valTemp;


    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numPaymentMethod==0)?1:numPaymentMethod); i++)
    {
        addr_obj1.push_back( Pair( "@class", nom[i].atclass ) );

        addr_obj1.push_back( Pair( "id", nom[i].id ) );
        addr_obj1.push_back( Pair( "responsible", nom[i].responsible ) );
        addr_obj1.push_back( Pair( "type", nom[i].type ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numPaymentMethod==0)
    {
        objPaymentMethod=int_vect1[0];

    }
    else
    {
        valPaymentMethod= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonPhones(Phones *nom, int numPhones, Object &objPhones, Value &valPhones)
{
    Object addr_obj1;
    vector< Object > int_vect1;
    Object objCountry;
    Value valTemp;

    for(int i=0; i<((numPhones==0)?1:numPhones); i++)
    {
        addr_obj1.push_back( Pair( "phoneNumber", nom[i].phoneNumber) );

        this->buildJsonCountry(&nom[i].country,0, objCountry, valTemp);
        addr_obj1.push_back(Pair( "country", objCountry ));
        objCountry.clear();

        addr_obj1.push_back( Pair( "type", nom[i].type) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numPhones==0)
    {
        objPhones=int_vect1[0];

    }
    else
    {
        valPhones= Value( int_vect1.begin(), int_vect1.end() );

    }
}

bool buildJson::buildJsonPermissions(Permissions *nom, int numPermissions, Object &objPermissions, Value &valPermissions)
{
    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numPermissions==0)?1:numPermissions); i++)
    {

        addr_obj1.push_back( Pair( "permissionName",  nom[i].permissionName ) );
        addr_obj1.push_back( Pair( "canEdit", nom[i].canEdit ) );
        addr_obj1.push_back( Pair( "canDelete", nom[i].canDelete ) );
        addr_obj1.push_back( Pair( "canRead", nom[i].canRead) );
        addr_obj1.push_back( Pair( "canAdd", nom[i].canAdd ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numPermissions==0)
    {
        objPermissions=int_vect1[0];

    }
    else
    {
        valPermissions= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonTicket(Ticket *tick, int numTicket, Object &objectOut, Value &valueOut)
{
    Object objUser, objTemp;
    Value valTemp;
    Object ticket1;
    vector< Object > tick_vect1;

    for(int i=0; i<((numTicket==0)?1:numTicket); i++)
    {
        ticket1.push_back( Pair( "isClosed", tick[i].isClosed) );
        ticket1.push_back( Pair( "id", (int)tick[i].id ) );
        ticket1.push_back( Pair( "subject", tick[i].subject ) );
        ticket1.push_back( Pair( "assignedTo", tick[i].assignedTo ) );
        ticket1.push_back( Pair( "name", tick[i].name ) );
        ticket1.push_back( Pair( "dateOpen", tick[i].dateOpen ) );
        ticket1.push_back( Pair( "resolved", tick[i].resolved ) );
        ticket1.push_back( Pair( "type", tick[i].type ) );
        ticket1.push_back( Pair( "status", tick[i].status ) );
        ticket1.push_back( Pair( "dateCreated", tick[i].dateCreated ) );
        ticket1.push_back( Pair( "lastActivity", tick[i].lastActivity ) );

        this->buildJsonUser(&tick[i].owner,0, objUser, valTemp);
        ticket1.push_back(Pair( "owner", objUser ));
        objUser.clear();

        this->buildJsonNotes(tick[i].notes, tick[i].numNotes, objTemp, valTemp);
        ticket1.push_back( Pair( "notes",valTemp) );

        tick_vect1.push_back( ticket1 );
        ticket1.clear();
    }

    if(numTicket==0)
    {
        objectOut=tick_vect1[0];

    }
    else
    {
        valueOut= Value( tick_vect1.begin(), tick_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonTerminal(Terminal *nom, int numTerminal, Object &objectOut, Value &valueOut)
{
    Object terminal1;
    vector< Object > term_vect1;

    for(int i=0; i<((numTerminal==0)?1:numTerminal); i++)
    {
        terminal1.push_back( Pair( "id", (int)nom[i].id) );
        terminal1.push_back( Pair( "name", nom[i].name ) );
        terminal1.push_back( Pair( "details", nom[i].details ) );

        term_vect1.push_back( terminal1 );
        terminal1.clear();
    }

    if(numTerminal==0)
    {
        objectOut=term_vect1[0];

    }
    else
    {
        valueOut= Value( term_vect1.begin(), term_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonConsumer(Consumer *nom, int numConsumer,Object &objectOut, Value &valueOut)
{
    Object objTemp;
    Value valTemp;


    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numConsumer==0)?1:numConsumer); i++)
    {
        addr_obj1.push_back( Pair( "title", nom[i].title));
        addr_obj1.push_back( Pair( "birthDate", nom[i].birthDate));

        this->buildJsonAddress(&nom[i].mainaddress, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "mainAddress", objTemp));
        objTemp.clear();

        this->buildJsonAppSettings(&nom[i].appsettings, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "settings", objTemp ));
        objTemp.clear();

        this->buildJsonLoyaltySettings(&nom[i].loyaltysettings, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "loyaltySettings", objTemp ));
        objTemp.clear();

        this->buildJsonAddress(nom[i].address, nom[i].numAddress, objTemp, valTemp);
        addr_obj1.push_back( Pair( "addresses", valTemp ));

        this->buildJsonUser(&nom[i].user, 0, addr_obj1, valTemp);

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numConsumer==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }
}

bool buildJson::buildJsonInvoiceItem(InvoiceItem *nom, int numInvoiceItem, Object &objectOut, Value &valueOut)
{
    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numInvoiceItem==0)?1:numInvoiceItem); i++)
    {
        addr_obj1.push_back( Pair( "quantity", nom[i].quantity ) );
        addr_obj1.push_back( Pair( "totalCost", nom[i].totalCost ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numInvoiceItem==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonAccount(Account *nom, int numAccount, Object &objectOut, Value &valueOut)
{
    Object objTemp;
    Value valTemp;


    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numAccount==0)?1:numAccount); i++)
    {
        addr_obj1.push_back( Pair( "id", (int)nom[i].id ) );
        addr_obj1.push_back( Pair( "invoiceNumber", (int)nom[i].invoiceNumber) );
        addr_obj1.push_back( Pair( "ammount", nom[i].ammount) );
        addr_obj1.push_back( Pair( "companyName", nom[i].companyName) );
        addr_obj1.push_back( Pair( "dateIssued", nom[i].dateIssued) );
        addr_obj1.push_back( Pair( "dateDue", nom[i].dateDue) );
        addr_obj1.push_back( Pair( "type", nom[i].type) );
        addr_obj1.push_back( Pair( "priority", nom[i].priority) );


        this->buildJsonConsumer(&nom[i].consumer, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "client", objTemp ));
        objTemp.clear();

        this->buildJsonInvoiceItem(nom[i].invoiceitem, nom[i].numInvoiceItem, objTemp, valTemp);
        addr_obj1.push_back( Pair( "items", valTemp ));

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numAccount==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonAdminAppSettings(AdminAppSettings *nom, int numAdminAppSettings, Object &objectOut, Value &valueOut)
{
    Object adminappsettings1;
    vector< Object > int_vect1;
    Value valTemp;

    for(int i=0; i<((numAdminAppSettings==0)?1:numAdminAppSettings); i++)
    {
        this->buildJsonAppSettings(&nom[i].appSettings, 0, adminappsettings1, valTemp);

        adminappsettings1.push_back( Pair( "pushNotification", nom[i].pushNotification) );
        adminappsettings1.push_back( Pair( "mute", nom[i].mute ) );
        adminappsettings1.push_back( Pair( "vibrate", nom[i].vibrate ) );
        adminappsettings1.push_back( Pair( "refund", nom[i].refund) );
        adminappsettings1.push_back( Pair( "systemAlerts", nom[i].systemAlerts ) );
        adminappsettings1.push_back( Pair( "reminders", nom[i].reminders) );
        adminappsettings1.push_back( Pair( "scanTimeout", nom[i].scanTimeout) );
        adminappsettings1.push_back( Pair( "expandGiftCard", nom[i].expandGiftCard ));

        this->buildJsonAppSettings(&nom[i].appSettings, 0, adminappsettings1, valTemp);

        int_vect1.push_back( adminappsettings1 );
        adminappsettings1.clear();
    }

    if(numAdminAppSettings ==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }
return true;
}

bool buildJson::buildJsonConsumerCreditCard(ConsumerCreditCard *nom, int numConsumerCreditCard, Object &objectOut, Value &valueOut)
{
    Object consumercreditcard1;
    vector< Object > int_vect1;

    for(int i=0; i<((numConsumerCreditCard==0)?1:numConsumerCreditCard); i++)
    {
        consumercreditcard1.push_back( Pair( "cvv", nom[i].cvv) );
        consumercreditcard1.push_back( Pair( "id",(int)nom[i].id) );
        consumercreditcard1.push_back( Pair( "holderName", nom[i].holderName) );
        consumercreditcard1.push_back( Pair( "pan", nom[i].pan) );
        consumercreditcard1.push_back( Pair( "expirationDate", nom[i].expirationDate) );
        consumercreditcard1.push_back( Pair( "PaymentMethodType", nom[i].PaymentMethodType) );

        int_vect1.push_back( consumercreditcard1 );
        consumercreditcard1.clear();
    }

    if(numConsumerCreditCard==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }
return true;
}

bool buildJson::buildJsonCoupon(Coupon *nom, int numCoupon, Object &objectOut, Value &valueOut)
{
    Object objTemp;

    Value valTemp;

    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numCoupon==0)?1:numCoupon); i++)
    {

        this->buildJsonLoyaltyProgram(&nom[i].loyaltyProgram, 0, addr_obj1, valTemp);

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numCoupon==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonInvoice(Invoice *nom, int numInvoice, Object &objectOut, Value &valueOut)
{
    Object objTemp;
    Value valTemp;


    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numInvoice==0)?1:numInvoice); i++)
    {
        addr_obj1.push_back( Pair( "id", (int)nom[i].id ) );
        addr_obj1.push_back( Pair( "transactionId", nom[i].transactionId) );
        addr_obj1.push_back( Pair( "transactionType", nom[i].transactionType) );
        addr_obj1.push_back( Pair( "transactionDate", nom[i].transactionDate) );

        this->buildJsonMerchant(&nom[i].merchant, 0,  objTemp, valTemp);
        addr_obj1.push_back( Pair( "merchant", objTemp ));
        objTemp.clear();

        this->buildJsonConsumer(&nom[i].consumer, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "consumer", objTemp ));
        objTemp.clear();

        this->buildJsonAddress(&nom[i].address, 0,  objTemp, valTemp);
        addr_obj1.push_back( Pair( "shippingAddress", objTemp ));
        objTemp.clear();

        addr_obj1.push_back( Pair( "totalAmount", nom[i].totalAmount) );
        addr_obj1.push_back( Pair( "itemsAmount", nom[i].itemsAmount) );
        addr_obj1.push_back( Pair( "savingAmount", nom[i].savingAmount) );

        this->buildJsonPaymentMethod(&nom[i].paymentmethod, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "paymentmethod", objTemp ));
        objTemp.clear();

        this->buildJsonInvoiceItem(nom[i].invoiceitem, nom[i].numInvoiceItem, objTemp, valTemp);
        addr_obj1.push_back( Pair( "items", valTemp ));

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();

    }

    if(numInvoice==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonClubMembership(ClubMembership *nom, int numClubMembership, Object &objectOut, Value &valueOut)
{
    Object objTemp;
    Value valTemp;


    Object clubmembership1;
    vector< Object > int_vect1;

    for(int i=0; i<((numClubMembership==0)?1:numClubMembership); i++)
    {
        this->buildJsonLoyaltyProgram(&nom[i].loyaltyProgram, 0,  clubmembership1, valTemp);

        clubmembership1.push_back( Pair( "logoImage", nom[i].logoImage) );
        clubmembership1.push_back( Pair( "needsFaces",nom[i].needsFaces) );

        this->buildJsonFaceImages(nom[i].faceimages, nom[i].numFaceImages, objTemp, valTemp);
        clubmembership1.push_back( Pair( "facesImages",valTemp) );

        int_vect1.push_back( clubmembership1 );
        clubmembership1.clear();
    }

    if(numClubMembership==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }
return true;
}

bool buildJson::buildJsonLoyaltyProgram(LoyaltyProgram *nom, int numLoyaltyProgram, Object &objectOut, Value &valueOut)
{
    Object objTemp;

    Value valTemp;

    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numLoyaltyProgram==0)?1:numLoyaltyProgram); i++)
    {
        addr_obj1.push_back( Pair( "@class", nom[i].atclass ) );

        addr_obj1.push_back( Pair( "id", (int)nom[i].id ) );
        addr_obj1.push_back( Pair( "originalPrice", nom[i].originalPrice) );
        addr_obj1.push_back( Pair( "salePrice", nom[i].salePrice) );
        addr_obj1.push_back( Pair( "recurringCharge", nom[i].recurringCharge) );
        addr_obj1.push_back( Pair( "recurringChargeAmount", nom[i].recurringChargeAmount) );
        addr_obj1.push_back( Pair( "dateCreated", nom[i].dateCreated) );
        addr_obj1.push_back( Pair( "dateActive", nom[i].dateActive) );
        addr_obj1.push_back( Pair( "dateExpire", nom[i].dateExpire) );
        addr_obj1.push_back( Pair( "name", nom[i].name) );
        addr_obj1.push_back( Pair( "termsAndConditios", nom[i].termsAndConditios) );
        addr_obj1.push_back( Pair( "barcodeImage", nom[i].barcodeImage) );
        addr_obj1.push_back( Pair( "upcCode", nom[i].upcCode) );
        addr_obj1.push_back( Pair( "brand", nom[i].brand) );
        addr_obj1.push_back( Pair( "image", nom[i].image) );

        this->buildJsonCategories(&nom[i].category, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "category", objTemp));
        objTemp.clear();

        addr_obj1.push_back( Pair( "recurringChargesCurrency", nom[i].recurringChargesCurrency) );

        this->buildJsonLocation(nom[i].location, nom[i].numLocation, objTemp, valTemp);
        addr_obj1.push_back( Pair( "participatingLocations", valTemp ));

        this->buildJsonRemoteItems(nom[i].remoteitem, nom[i].numRemoteItem, objTemp, valTemp);
        addr_obj1.push_back( Pair( "remoteItems", valTemp));

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numLoyaltyProgram==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonMerchantAppSettings(MerchantAppSettings *nom, int numMerchantAppSettings,  Object &objectOut, Value &valueOut)
{
    Object addr_obj1;
    vector< Object > int_vect1;
    Value valTemp;

    for(int i=0; i<((numMerchantAppSettings==0)?1:numMerchantAppSettings); i++)
    {
        this->buildJsonAppSettings(&nom[i].appSettings, 0, addr_obj1, valTemp);

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numMerchantAppSettings==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonRating(Rating *nom, int numRating, Object &objectOut, Value &valueOut)
{
    Object objTemp;

    Value valTemp;


    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numRating==0)?1:numRating); i++)
    {
        addr_obj1.push_back( Pair( "id", (int)nom[i].id ) );
        addr_obj1.push_back( Pair( "rate", nom[i].rate) );

        this->buildJsonUser(&nom[i].rater, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "rater", objTemp ));
        objTemp.clear();

        this->buildJsonUser(&nom[i].rated, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "rated", objTemp ));
        objTemp.clear();

        addr_obj1.push_back( Pair( "rateDate", nom[i].rateDate) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numRating==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonReseller(Reseller *nom, int numReseller, Object &objectOut, Value &valueOut)
{
    Object objTemp;
    Value valTemp;

    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numReseller==0)?1:numReseller); i++)
    {
        addr_obj1.push_back( Pair( "assignedTo", nom[i].assignedTo ) );
        addr_obj1.push_back( Pair( "supervisor", nom[i].supervisor) );
        addr_obj1.push_back( Pair( "department", nom[i].department) );

        this->buildJsonAppSettings(&nom[i].appsettings, 0, objTemp, valTemp);
        addr_obj1.push_back( Pair( "settings", objTemp ));
        objTemp.clear();

        this->buildJsonSuscription(nom[i].suscription, nom[i].numSuscription, objTemp, valTemp);
        addr_obj1.push_back( Pair( "suscriptions", valTemp ));

        this->buildJsonLocation(nom[i].location, nom[i].numLocation, objTemp, valTemp);
        addr_obj1.push_back( Pair( "locations", valTemp ));

        this->buildJsonMerchant(nom[i].merchant, nom[i].numMerchant, objTemp, valTemp);
        addr_obj1.push_back( Pair( "customers", valTemp ));

        this->buildJsonUser(&nom[i].user, nom[i].numMerchant, addr_obj1, valTemp);

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numReseller==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonResellerAppSettings(ResellerAppSettings *nom, int numResellerAppSettings, Object &objectOut, Value &valueOut)
{
    Object addr_obj1;
    vector< Object > int_vect1;
    Value val1;

    for(int i=0; i<((numResellerAppSettings==0)?1:numResellerAppSettings); i++)
    {
        this->buildJsonAppSettings(&nom[i].appsettings, 0, addr_obj1, val1);

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numResellerAppSettings==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonSellerPaymentMethod(SellerPaymentMethod *nom, int numSellerPaymentMethod,  Object &objectOut, Value &valueOut)
{
    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numSellerPaymentMethod==0)?1:numSellerPaymentMethod); i++)
    {
        addr_obj1.push_back( Pair( "id", (int)nom[i].id ) );
        addr_obj1.push_back( Pair( "issuer", nom[i].issuer ) );
        addr_obj1.push_back( Pair( "merchantId", nom[i].merchantId ) );
        addr_obj1.push_back( Pair( "type", nom[i].type ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numSellerPaymentMethod==0)
    {
        objectOut=int_vect1[0];

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }

    return true;
}

bool buildJson::buildJsonFaceImages(string *nom, int numFaceImages, Object &objectOut, Value &valueOut)
{
    vector< string > int_vect1;


    for(int i=0; i<((numFaceImages==0)?1:numFaceImages); i++)
    {
        int_vect1.push_back( nom[i] );
    }

    if(numFaceImages==0)
    {

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;

    }
    return true;
}

bool buildJson::buildJsonNotes(string *nom, int numNotes, Object &objectOut, Value &valueOut)
{
    vector< string > int_vect1;


    for(int i=0; i<((numNotes==0)?1:numNotes); i++)
    {
        int_vect1.push_back( nom[i] );
    }

    if(numNotes==0)
    {

    }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );
        //logbasic << write_formatted(val6) << endl;
    }
    return true;
}

bool buildJson::buildJsonCountry(Country *nom, int numCountry , Object &objectOut, Value &valueOut)
{
    Object addr_obj1;
    vector< Object > int_vect1;

    for(int i=0; i<((numCountry==0)?1:numCountry); i++)
    {
        addr_obj1.push_back( Pair( "available", nom[i].available ) );
        addr_obj1.push_back( Pair( "code", nom[i].code ) );
        addr_obj1.push_back( Pair( "name", nom[i].name ) );
        addr_obj1.push_back( Pair( "shortName", nom[i].shortName ) );

        int_vect1.push_back( addr_obj1 );
        addr_obj1.clear();
    }

    if(numCountry==0)
    {
        objectOut=int_vect1[0];
            }
    else
    {
        valueOut= Value( int_vect1.begin(), int_vect1.end() );

    }

    return true;
}

#endif
