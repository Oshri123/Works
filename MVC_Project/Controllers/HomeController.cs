using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Project.Models;
using Project.Dal;
using Project.ModelView;

namespace Project.Controllers
{
    public class HomeController : Controller
    {
        public static String usName;

        public ActionResult Index(User user)
        {
            User tempUser = new User();
            if (user.UserName != null && user.UserName != "")
            {
                tempUser = user;
            }

            return View(tempUser);
        }

        public ActionResult PetsCareTips(User user)
        {
            return View(user);
        }

        public ActionResult About(User user)
        {
            ViewBag.Message = "Our application description page.";

            return View(user);
        }

        public ActionResult Contact(User user)
        {
            ViewBag.Message = "Our contact page.";

            return View(user);
        }

        public ActionResult WritingFeedback(User user)
        {
            return View(user);
        }

        [HttpPost]
        public ActionResult Submit(String Feedback, String Name, User user)
        {
            if (Name!="" && Feedback!="")
            {

                Feedback fb = new Feedback()
                {
                    name = Name,
                    feedback = Feedback
                };

                FeedbackDal fdal = new FeedbackDal();

                fdal.feedbacks.Add(fb);
                fdal.SaveChanges();

                return View("Index", user);

            }
            else if(Name=="")
            {
                TempData["ErorName"] = "You must enter name!";
                return View("WritingFeedback", user);
            }
            else
            {
                TempData["ErorFeedback"] = "You must enter Feedback!";
                return View("WritingFeedback", user);
            }
        }

        public ActionResult ReadingFeedback(User user)
        {
            return View(user);
        }

        public ActionResult GetShoppingCart(User user)
        {
            int listLength = 0;
            ShoppingCartDal scDal = new ShoppingCartDal();
            List<ShoppingCart> objShoppingCart =
                (from x in scDal.shoppingCart
                 where x.customer == user.UserName
                 select x).ToList<ShoppingCart>();

            foreach (ShoppingCart sc in objShoppingCart)
                listLength++;

            if (listLength == 0)
            {
                objShoppingCart = null;
            }
            VMUser vm = new VMUser(user,objShoppingCart);
            return View("ShowShoppingCart",vm);    

        }

        public ActionResult GetFeedbackByJason()
        {

            FeedbackDal fdal = new FeedbackDal();
            List<Feedback> objFeedback = fdal.feedbacks.ToList<Feedback>();

            return Json(objFeedback, JsonRequestBehavior.AllowGet);
        }

    }
}