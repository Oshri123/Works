using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Project.Models
{
    public class Feedback
    {
        [Key]
        [Required]
        public String name { get; set; }

        [Required]
        public String feedback { get; set; }
    }
}