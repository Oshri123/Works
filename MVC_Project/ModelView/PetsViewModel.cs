using Project.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Project.ModelView
{
    public class PetsViewModel
    {
        public Pets pet { get; set; }

        public List<Pets> pets { get; set; }
    }
}