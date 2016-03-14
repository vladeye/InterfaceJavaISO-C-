
#ifndef __UNPACK_JSON_H
#define __UNPACK_JSON_H

#include <string>
#ifdef __nmc_json

#include "json_spirit.h"
#include <cassert>
#include <fstream>

#ifndef JSON_SPIRIT_VALUE_ENABLED
#error Please define JSON_SPIRIT_VALUE_ENABLED for the Value type to be enabled
#endif

using namespace std;
using namespace json_spirit;

struct CategoryWeb
{
    string shipping_amt;
    string option2_caption;
    string phone_number;
    string merchant_location_id;
    string im_id;
    string coupon_id;
    string state;
    string coupon_details;
    string shipping_types;
    string valid_from_date;
    string im_zip;
    string mycoupon;
    string recommended_items;
    string used;
    string impulse;
    string city;
    string option1;
    string amount;
    string option2;
    string distance;
    string coupon_title;
    string locationid;
    string im_title;
    string im_address2;
    string im_address;
    string im_state;
    string im_city;
    string longitude;
    string coupon_required_items;
    string option1_caption;
    string im_mname;
    string zip;
    string barcode;
    string coupon_summary;
    string companyname;
    string merchantid;
    string discount;
    string valid_until_date;
    string address;
    string coupon_added_date;
    string coupon_image;
    string shipping_ids;
    string used_satatus;
    string im_type;
    string latitude;
};

struct CouponCategoryWeb
{
    string parentid;
    string coupon_category_name;
    string status;
    string coupon_category_id;
};

struct MerchantWeb
{
    string zip;
    string locationid;
    string address;
    string state;
    string companyname;
    string country;
    string merchantid;
    string city;
};

struct ConsumerWeb
{
    string home_phone_number;
    string phone_number;
    string state;
    string address2;
    string billing_state;
    string password;
    string city;
    string billing_country;
    string first_name;
    string title;
    string register_date;
    string fin;
    string ini;
    string zip;
    string billing_address2;
    string middle_name;
    string date_of_birth;
    string country;
    string billing_zip;
    string mobile_number_carrier_id;
    string email;
    string address;
    string billing_city;
    string last_name;
    string billing_address;
};



class UnpackJson
{
    public:
        UnpackJson();
        //bool unpackJsonUser(User *nom, int numUser, Object &objectOut, Value &valueOut);
        bool unpackJsonCategoryWeb(CategoryWeb *nom, int asize, Object &objectOut, const Array &arrayOut);
        bool unpackJsonCouponCategoryWeb(CouponCategoryWeb *nom, int asize, Object &objectOut, const Array &arrayOut);
        bool unpackJsonMerchantWeb(MerchantWeb *nom, int asize, Object &objectOut, const Array &arrayOut);
        bool unpackJsonConsumerWeb(ConsumerWeb *nom, int asize, Object &objectOut, const Array &arrayOut);

        virtual ~UnpackJson();
};


#endif


#endif
