using Project.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Project.ModelView
{
    public class UserViewModel
    {

        public UserInfo userInfo { get; set; }

        public User user { get; set; }


        public Feedback fb { get; set; }

        public List<UserInfo> users { get; set; }

    }
}