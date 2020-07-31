// pages/index/index.js
const db = wx.cloud.database();

Page({

  /**
   * 页面的初始数据
   */
  data: {
    radioItems: [
      {name: '普通客户', checked: 'true'},
      {name: '客服'},
      {name: '维修人员'}
    ],
    user:'普通客户',
    username:"",
    password:""
  },

  radioChange:function(e){
    this.setData({
      user: e.detail.value
    })
  },

  inputUsername:function(e){
    this.setData({
      username: e.detail.value
    });
  },

  inputPassword:function(e){
    this.setData({
      password: e.detail.value
    });
  },

  kehulogin(event){
    db.collection('kehu').where({
      username:this.data.username,
      password:this.data.password
    }).get().then(res=>{
      if(res.data[0]==null){
        wx.showToast({
          title: '输入错误',
          icon: 'none',
        })
      }
      else if(res.data[0].username==this.data.username){
        var app = getApp();
        app.globalData.globalName = this.data.username;
        wx.showToast({
          title:'登录成功',
          icon: 'success',
        })
        setTimeout(function () {
          wx.switchTab({
            url: '/pages/index1/index1'
          })
        }, 2000);
      }
    })
  },

  kefulogin(event){
    db.collection('kefu').where({
      username:this.data.username,
      password:this.data.password
    }).get().then(res=>{
      if(res.data[0]==null){
        wx.showToast({
          title: '输入错误',
          icon: 'none',
        })
      }
      else if(res.data[0].username==this.data.username){
        var app = getApp();
        app.globalData.globalName = this.data.username;
        wx.showToast({
          title:'登录成功',
          icon: 'success',
        })
        setTimeout(function () {
          wx.redirectTo({
            url: '/pages/kefuindex4/kefuindex4'
          })
        }, 2000);
      }
    })
  },

  wxglogin(event){
    db.collection('wxg').where({
      username:this.data.username,
      password:this.data.password
    }).get().then(res=>{
      if(res.data[0]==null){
        wx.showToast({
          title: '输入错误',
          icon: 'none',
        })
      }
      else if(res.data[0].username==this.data.username){
        var app = getApp();
        app.globalData.globalName = this.data.username;
        wx.showToast({
          title:'登录成功',
          icon: 'success',
        })
        setTimeout(function () {
          wx.redirectTo({
            url: '/pages/wxgindex4/wxgindex4'
          })
        }, 2000);
      }
    })
  },

  login: function(e){
    if(this.data.user=='普通客户'){
      this.kehulogin(e);
    }
    else if(this.data.user=='客服'){
      this.kefulogin(e);
    }
    else if(this.data.user=='维修人员'){
      this.wxglogin(e);
    }
  },


  register: function(){
    wx.navigateTo({
      url: '/pages/register/register',
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})