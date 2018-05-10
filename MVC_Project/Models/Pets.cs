﻿using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Project.Models
{
    public class Pets
    {
        [Required]
        [StringLength(50)]
        public string petType { get; set; }

        [Required]
        [StringLength(50)]
        [RegularExpression("^([A-Z]|[a-z])+$")]
        public string petName { get; set; }

        [Required]
        [StringLength(50)]
        [RegularExpression("^([1-9][0-9]*)$")]
        public string petPrice { get; set; }

        [Required]
        public int Availability { get; set; }

        [Key]
        [Required]
        [StringLength(50)]
        [RegularExpression("^[0-9]+$")]
        public string petID { get; set; }
    }
}