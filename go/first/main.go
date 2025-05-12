package main

import (
	"fmt"

	"github.com/gofiber/fiber/v2"
)

// Membuat Instance App
// Membuat Route GET & POST
// Memberikan Response
// Menerima Params, Query dan Body
// Membuat Static Route
// Memberikan Response JSON

type LoginData struct {
	Username string `json:"username"`
	Password string `json:"password"`
}

func main() {
	
	app := fiber.New();

	app.Get("/", func(c *fiber.Ctx) error {
		return c.SendString("Hello Worlds")
	})

	app.Get("/sayhello/:nama", func(c *fiber.Ctx) error {
		var nama string = c.Params("nama")

		return c.SendString(fmt.Sprintf("Hello %s", nama))
	})

	app.Get("/search", func(c *fiber.Ctx) error {
		var searchValue string = c.Query("s");

		return c.SendString(fmt.Sprintf("Hasil yang anda cari : %s", searchValue));
	})

	app.Post("/login", func(c *fiber.Ctx) error {
		var loginData LoginData;

		err := c.BodyParser(&loginData)

		if err != nil{
			fmt.Println("Error")
			return c.SendString("Ada yang salah dengan kode mu");
		}

		// message, status, feedback
		return c.JSON(fiber.Map{
			"status":200,
			"message":"Berhasil Login",
			"data":loginData,
		})
	})

	app.Static("/profil", "./assets")

	app.Listen(":3000")

}