using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Project.Models
{
    public class User
    {
        [Key]
        [Required]
        public string UserName { get; set; }

        [Required]
        [RegularExpression(pattern: "^[0-9]{4}$")]
        public string Password { get; set; }

        public int IsManager { get; set; }

        //public User()
        //{ }
        //public User(User previousUser)
        //{
        //    UserName = previousUser.UserName;
        //    Password = previousUser.Password;
        //    IsManager = previousUser.IsManager;

        //}
    }
}
