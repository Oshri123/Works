using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Project.Models
{
    public class UserInfo
    {
        [Required]
        [StringLength(50)]
        [RegularExpression("^([A-Z]|[a-z])+$")]
        public string FirstName { get; set; }
        
        [Required]
        [StringLength(50)]
        [RegularExpression("^([A-Z]|[a-z])+$")]
        public string LastName { get; set; }

        [Key]
        [Required]
        [StringLength(50)]
        public string UserName { get; set; }

        [StringLength(50)]
        public string LovedPet { get; set; }

        [Required]
        public int PurchasedPet { get; set; }

        [Required]
        [RegularExpression(pattern: "^[0-9]{4}$")]
        public string Password { get; set; }
    }
}