using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClassXamLib
{

    public class CheckPoint
    {
        public abstract Dictionary<string, object> executeService(Dictionary<string, string> data, string methodName){
            AbsService ServiceW;
            Dictionary<string, dynamic> result = new Dictionary<string, dynamic>();
            
            if (Constants.Methods["VALIDATE"] != "")
            {
                Type myTypeObj = Type.GetType(Constants.Methods["VALIDATE"]);
                ServiceW = (AbsService)Activator.CreateInstance(myTypeObj);
                result = ServiceW.executeService(data);
            }

            return result;
        }        
    }
}
