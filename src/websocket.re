open Koa;

module Socket = {
  type t('a) = App.t;

  type ws('a) = {.
    use: App.middleware('a)
  };

  [@bs.module] external make: t('a) => t('a) = "koa-websocket";
};