using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClassXamLib
{
    abstract class AbsService
    {
        public abstract Dictionary<string, object> executeService(Dictionary<string, string> data);
    }
}
