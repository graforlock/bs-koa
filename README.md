# bs-koa [WIP]

Bindings to koa and koa-route.

Example:

```ocaml
open Koa;
open KoaRoute;
open KoaWebsocket; 

let app = App.make ();
let route = Route.route;
let ws: Socket.ctx(string, string) = Socket.ws(app);

let opts: Route.options = [||];

App.use(app, (ctx, next) => {
  ctx##body #= "Hello World!";
  next();
});

App.use(app,
  Route.get(route, "/:hummus", (ctx, param) => {
    ctx##body #= param;
  }, ~opts=opts)
);

Socket.use(ws,(ctx, next) => {
  ctx##websocket##send("Hello World!");
  ctx##websocket##on("message", msg => Js.log(msg) |> ignore);
  next();
});

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
```