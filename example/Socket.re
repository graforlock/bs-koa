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
  ctx##websockets##send("Hello World!");
  next();
});

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
