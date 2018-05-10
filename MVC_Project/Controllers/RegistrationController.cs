using Project.Dal;
using Project.Models;
using Project.ModelView;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;
using System.Web;
using System.Web.Mvc;

namespace Project.Controllers
{
    public class RegistrationController : Controller
    {
        // GET: Registration

        public ActionResult Enter()
        {
            return View(new User());
        }

        public ActionResult Register()
        {
            return View();
        }

        public ActionResult Submit()
        {
            UserInfo uf = new UserInfo()
            {
                UserName = Request.Form["userInfo.UserName"].ToString(),
                Password = Request.Form["userInfo.Password"].ToString(),
                FirstName = Request.Form["userInfo.FirstName"].ToString(),
                LastName = Request.Form["userInfo.LastName"].ToString(),
                LovedPet = Request.Form["userInfo.LovedPet"].ToString()
            };

            //
            User objUser = new User()
            {
                UserName = uf.UserName,
                Password = uf.Password
            };

            UsersInfoDal UIDal = new UsersInfoDal();
            UserDal dal = new UserDal();

            if (ModelState.IsValid)
            {
                if (dal.Users.Find(objUser.UserName) != null)
                {
                    TempData["Eror"] = "there is already user with this name";
                    return View("Register",uf);
                }
                else
                {
                    dal.Users.Add(objUser);
                    dal.SaveChanges();
                    UIDal.usersInfo.Add(uf);
                    UIDal.SaveChanges();
                    return View("~/Views/Home/Index.cshtml", objUser);

                }

            }
            else
            {
                TempData["Eror"] = "there value is not valid";
                return View("Register",uf);
            }

        }

        public ActionResult Login(User objUser)
        {

            UserDal dal = new UserDal();

            User user = dal.Users.Find(objUser.UserName);

            if (ModelState.IsValid)
            {
                if (user != null)
                {
                    if (user.Password == objUser.Password)
                        return View("~/Views/Home/Index.cshtml", dal.Users.Find(objUser.UserName));
                    else
                    {
                        TempData["PasswordLoginError"] = "The password is wrong";
                        return View("Enter", objUser);
                    }
                }
                else
                {
                    TempData["NameLoginError"] = "This User name is not exist";
                    return View("Enter", objUser);
                }
            }
            else
            {
                TempData["LoginError"] = "The User name is not valid";
                return View("Enter", objUser);
            }
        }

        public ActionResult ShowUsers(User user)
        {
            return View(user);
        }

        public ActionResult GetUsersByJason()
        {

            UsersInfoDal dal = new UsersInfoDal();
            List<UserInfo> objUSers = dal.usersInfo.ToList<UserInfo>();
            return Json(objUSers, JsonRequestBehavior.AllowGet);
        }
    }
}