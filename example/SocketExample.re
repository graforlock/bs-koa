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

Socket.use(ws,
  Route.all(route, "/:halloumi", (ctx, param, _) => {
    Socket.onMessage(ctx, msg => Js.log(msg) |> ignore);
    Socket.send(ctx, {j| Yummy $param !|j});
  }, ~opts=opts)
);

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
