using Project.Dal;
using Project.Models;
using Project.ModelView;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Project.Controllers
{
    public class PetsController : Controller
    {
        // GET: Pets

        public ActionResult AddPets(User user)
        {
            Session["UserName"] = user.UserName;
            VMUser vm = new VMUser(user,new Pets());
            return View(vm);
        }

        [HttpPost]
        public ActionResult SubmitPets(User user,string select)
        {

            Pets pet = new Pets
            {
                petName = Request.Form["pet.petName"].ToString(),
                petType = select,
                petID = Request.Form["pet.petID"].ToString(),
                petPrice = Request.Form["pet.petPrice"].ToString(),
                Availability = 1
            };

            PetsDal dal = new PetsDal();

                if (dal.pets.Find(pet.petID) != null)
                {
                    TempData["Eror"] = "there is already pet with this ID!";
                    return View("AddPets", user);
                }
                else
                {
                    dal.pets.Add(pet);
                    dal.SaveChanges();
                    return View("~/Views/Home/Index.cshtml", user);
                }
            }

        public ActionResult BuyPet(User user)
        {
            return View(user);
        }

        [HttpPost]
        public ActionResult SellingPets(User user, String id)
        {
            PetsDal dal = new PetsDal();
            UsersInfoDal ufDal = new UsersInfoDal();
            ShoppingCartDal scDal = new ShoppingCartDal();
            ShoppingCart sc = new ShoppingCart();

            if (user.UserName == null)
            {
                TempData["PetsError"] = "Sorry, You must login to buy pets!";
                return View("BuyPet", user);
            }

            if (id=="")
            {
                TempData["PetsError"] = "Sorry, You must enter value!";
                return View("BuyPet", user);
            }

            if (dal.pets.Find(id) != null)
            {
                if (dal.pets.Find(id).Availability == 1)
                {
                    //Initializing the shopping cart object
                    sc.petType = dal.pets.Find(id).petType;
                    sc.petName = dal.pets.Find(id).petName;
                    sc.petID = dal.pets.Find(id).petID;
                    sc.customer = user.UserName;

                    //Add the object to the shopping cart sql table
                    scDal.shoppingCart.Add(sc);
                    scDal.SaveChanges();

                    dal.pets.Find(id).Availability = 0;
                    dal.pets.Remove(dal.pets.Find(id));
                    dal.SaveChanges();
                    ufDal.usersInfo.Find(user.UserName).PurchasedPet++;
                    ufDal.SaveChanges();
                    return View("~/Views/Home/Index.cshtml", user);

                }
                else
                {
                    TempData["PetsError"] = "Sorry, this Pets is not Availabile! Try else pets.";
                    return View("BuyPet", user);
                }
            }
            else
            {
                TempData["PetsError"] = "The entered ID is not exist!";
                return View("BuyPet", user);
            }

        }

        public ActionResult PetsStore()
        {
            PetsDal PDal = new PetsDal();
            PetsViewModel pv = new PetsViewModel();
            pv.pets= PDal.pets.ToList<Pets>();
            return View(pv);
        }

        public ActionResult GetPetsByJason()
        {

            PetsDal PDal = new PetsDal();
            List<Pets> objPets = PDal.pets.ToList<Pets>();

            return Json(objPets, JsonRequestBehavior.AllowGet);
        }
    }
}