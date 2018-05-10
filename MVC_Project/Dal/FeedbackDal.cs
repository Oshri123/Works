using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using Project.Models;

namespace Project.Dal
{
    public class FeedbackDal : DbContext
    {

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
            modelBuilder.Entity<Feedback>().ToTable("tblFeedback");
        }

        public DbSet<Feedback> feedbacks { get; set; }
    }
}
