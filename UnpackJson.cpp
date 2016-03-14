#ifdef __nmc_json

#include "UnpackJson.h"

UnpackJson::UnpackJson(){}
UnpackJson::~UnpackJson(){}

bool UnpackJson::unpackJsonCategoryWeb(CategoryWeb *nom, int asize, Object &objectOut, const Array &arrayOut)
{
    for (int j = 0; j < arrayOut.size(); ++j)
    {
        const Object& o = (arrayOut[j]).get_obj();

        for (int i = 0; i < o.size(); ++i) {
            const Pair& p = o[i];

            if(p.name_=="shipping_amt"){
                nom[j].shipping_amt=(p.value_).get_value<string>();
            }
            else if(p.name_=="option2-caption"){
                nom[j].option2_caption=(p.value_).get_value<string>();
            }
            else if(p.name_=="phone_number"){
                nom[j].phone_number=(p.value_).get_value<string>();
            }
            else if(p.name_=="merchant_location_id"){
                nom[j].merchant_location_id=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-id"){
                nom[j].im_id=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_id"){
                nom[j].coupon_id=(p.value_).get_value<string>();
            }
            else if(p.name_=="state"){
                nom[j].state=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_details"){
                nom[j].coupon_details=(p.value_).get_value<string>();
            }
            else if(p.name_=="shipping_types"){
                nom[j].shipping_types=(p.value_).get_value<string>();
            }
            else if(p.name_=="valid_from_date"){
                nom[j].valid_from_date=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-zip"){
                nom[j].im_zip=(p.value_).get_value<string>();
            }
            else if(p.name_=="mycoupon"){
                nom[j].mycoupon=(p.value_).get_value<string>();
            }
            else if(p.name_=="recommended-items"){
                nom[j].recommended_items=(p.value_).get_value<string>();
            }
            else if(p.name_=="used"){
                nom[j].used=(p.value_).get_value<string>();
            }
            else if(p.name_=="impulse"){
                nom[j].impulse=(p.value_).get_value<string>();
            }
            else if(p.name_=="city"){
                nom[j].city=(p.value_).get_value<string>();
            }
            else if(p.name_=="option1"){
                nom[j].option1=(p.value_).get_value<string>();
            }
            else if(p.name_=="amount"){
                nom[j].amount=(p.value_).get_value<string>();
            }
            else if(p.name_=="option2"){
                nom[j].option2=(p.value_).get_value<string>();
            }
            else if(p.name_=="distance"){
                nom[j].distance=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_title"){
                nom[j].coupon_title=(p.value_).get_value<string>();
            }
            else if(p.name_=="locationid"){
                nom[j].locationid=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-title"){
                nom[j].im_title=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-address2"){
                nom[j].im_address2=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-address"){
                nom[j].im_address=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-state"){
                nom[j].im_state=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-city"){
                nom[j].im_city=(p.value_).get_value<string>();
            }
            else if(p.name_=="longitude"){
                nom[j].longitude=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_required_items"){
                nom[j].coupon_required_items=(p.value_).get_value<string>();
            }
            else if(p.name_=="option1-caption"){
                nom[j].option1_caption=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-mname"){
                nom[j].im_mname=(p.value_).get_value<string>();
            }
            else if(p.name_=="zip"){
                nom[j].zip=(p.value_).get_value<string>();
            }
            else if(p.name_=="barcode"){
                nom[j].barcode=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_summary"){
                nom[j].coupon_summary=(p.value_).get_value<string>();
            }
            else if(p.name_=="companyname"){
                nom[j].companyname=(p.value_).get_value<string>();
            }
            else if(p.name_=="merchantid"){
                nom[j].merchantid=(p.value_).get_value<string>();
            }
            else if(p.name_=="discount"){
                nom[j].discount=(p.value_).get_value<string>();
            }
            else if(p.name_=="valid_until_date"){
                nom[j].valid_until_date=(p.value_).get_value<string>();
            }
            else if(p.name_=="address"){
                nom[j].address=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_added_date"){
                nom[j].coupon_added_date=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_image"){
                nom[j].coupon_image=(p.value_).get_value<string>();
            }
            else if(p.name_=="shipping_ids"){
                nom[j].shipping_ids=(p.value_).get_value<string>();
            }
            else if(p.name_=="used_satatus"){
                nom[j].used_satatus=(p.value_).get_value<string>();
            }
            else if(p.name_=="used_satatus"){
                nom[j].used_satatus=(p.value_).get_value<string>();
            }
            else if(p.name_=="im-type"){
                nom[j].im_type=(p.value_).get_value<string>();
            }
            else if(p.name_=="latitude"){
                nom[j].latitude=(p.value_).get_value<string>();
            }
        }


    }


    return true;
}

bool UnpackJson::unpackJsonCouponCategoryWeb(CouponCategoryWeb *nom, int asize, Object &objectOut, const Array &arrayOut)
{
    for (int j = 0; j < arrayOut.size(); ++j)
    {
        const Object& o = (arrayOut[j]).get_obj();

        for (int i = 0; i < o.size(); ++i) {
            const Pair& p = o[i];

            if(p.name_=="parentid"){
                nom[j].parentid=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_category_name"){
                nom[j].coupon_category_name=(p.value_).get_value<string>();
            }
            else if(p.name_=="status"){
                nom[j].status=(p.value_).get_value<string>();
            }
            else if(p.name_=="coupon_category_id"){
                nom[j].coupon_category_id=(p.value_).get_value<string>();
            }
        }

    }

    return true;
}

bool UnpackJson::unpackJsonMerchantWeb(MerchantWeb *nom, int asize, Object &objectOut, const Array &arrayOut)
{
    for (int j = 0; j < arrayOut.size(); ++j)
    {
        const Object& o = (arrayOut[j]).get_obj();

        for (int i = 0; i < o.size(); ++i) {
            const Pair& p = o[i];

            if(p.name_=="zip"){
                nom[j].zip=(p.value_).get_value<string>();
            }
            else if(p.name_=="locationid"){
                nom[j].locationid=(p.value_).get_value<string>();
            }
            else if(p.name_=="address"){
                nom[j].address=(p.value_).get_value<string>();
            }
            else if(p.name_=="state"){
                nom[j].state=(p.value_).get_value<string>();
            }
            else if(p.name_=="companyname"){
                nom[j].companyname=(p.value_).get_value<string>();
            }
            else if(p.name_=="country"){
                nom[j].country=(p.value_).get_value<string>();
            }
            else if(p.name_=="merchantid"){
                nom[j].merchantid=(p.value_).get_value<string>();
            }
            else if(p.name_=="city"){
                nom[j].city=(p.value_).get_value<string>();
            }
        }


    }

    return true;
}

bool UnpackJson::unpackJsonConsumerWeb(ConsumerWeb *nom, int asize, Object &objectOut, const Array &arrayOut)
{
    for (int j = 0; j < arrayOut.size(); ++j)
    {
        const Object& o = (arrayOut[j]).get_obj();

        for (int i = 0; i < o.size(); ++i) {
            const Pair& p = o[i];

            if(p.name_=="home_phone_number"){
                nom[j].home_phone_number=(p.value_).get_value<string>();
            }
            else if(p.name_=="phone_number"){
                nom[j].phone_number=(p.value_).get_value<string>();
            }
            else if(p.name_=="state"){
                nom[j].state=(p.value_).get_value<string>();
            }
            else if(p.name_=="address2"){
                nom[j].address2=(p.value_).get_value<string>();
            }
            else if(p.name_=="billing_state"){
                nom[j].billing_state=(p.value_).get_value<string>();
            }
            else if(p.name_=="password"){
                nom[j].password=(p.value_).get_value<string>();
            }
            else if(p.name_=="city"){
                nom[j].city=(p.value_).get_value<string>();
            }
            else if(p.name_=="billing_country"){
                nom[j].billing_country=(p.value_).get_value<string>();
            }
            else if(p.name_=="first_name"){
                nom[j].first_name=(p.value_).get_value<string>();
            }
            else if(p.name_=="title"){
                nom[j].title=(p.value_).get_value<string>();
            }
            else if(p.name_=="register_date"){
                nom[j].register_date=(p.value_).get_value<string>();
            }
            else if(p.name_=="fin"){
                nom[j].fin=(p.value_).get_value<string>();
            }
            else if(p.name_=="ini"){
                nom[j].ini=(p.value_).get_value<string>();
            }
            else if(p.name_=="zip"){
                nom[j].zip=(p.value_).get_value<string>();
            }
            else if(p.name_=="billing_address2"){
                nom[j].billing_address2=(p.value_).get_value<string>();
            }
            else if(p.name_=="middle_name"){
                nom[j].middle_name=(p.value_).get_value<string>();
            }
            else if(p.name_=="date_of_birth"){
                nom[j].date_of_birth=(p.value_).get_value<string>();
            }
            else if(p.name_=="country"){
                nom[j].country=(p.value_).get_value<string>();
            }
            else if(p.name_=="billing_zip"){
                nom[j].billing_zip=(p.value_).get_value<string>();
            }
            else if(p.name_=="mobile_number_carrier_id"){
                nom[j].mobile_number_carrier_id=(p.value_).get_value<string>();
            }
            else if(p.name_=="email"){
                nom[j].email=(p.value_).get_value<string>();
            }
            else if(p.name_=="address"){
                nom[j].address=(p.value_).get_value<string>();
            }
            else if(p.name_=="billing_city"){
                nom[j].billing_city=(p.value_).get_value<string>();
            }
            else if(p.name_=="last_name"){
                nom[j].last_name=(p.value_).get_value<string>();
            }
            else if(p.name_=="billing_address"){
                nom[j].billing_address=(p.value_).get_value<string>();
            }
        }

    }

    return true;
}

#endif
