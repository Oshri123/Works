using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Project.Models
{
    public class VMUser
    {

        public User us { get; set; }

        public Pets pet { get; set; }

        public List<ShoppingCart> shoppingCart { get; set; }

        public VMUser(User u, Pets p)
        {
            us = u;
            pet = p;
        }

        public VMUser(User u, List<ShoppingCart> sc)
        {
            us = u;
            shoppingCart = sc;
        }

    }
}