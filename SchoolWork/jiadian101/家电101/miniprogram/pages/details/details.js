// miniprogram/pages/details/details.js
const db = wx.cloud.database({});

Page({

  /**
   * 页面的初始数据
   */
  data: {
    showView:true,
    pingjia:false,
    ping:false,
    zhifu:false,
    id:'',
  },

  zhifu:function(e){
    var id = this.data.id;
      wx.navigateTo({
        url: '/pages/zhifu/zhifu?id='+id,
      })
  },

  ping:function(e){
    var id = this.data.id;
    wx.navigateTo({
      url: '/pages/pingjia/pingjia?id='+id,
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.setData({
      id:options.id
    })
    db.collection('order').doc(options.id).get({
      success: res => {
        // res.data 包含该记录的数据
        this.setData({
          order: res.data
        })
        if(res.data.ddzt=='等待维修工接单'){
          this.setData({
            showView: false
          })
        };
        if(res.data.ddzt=='等待客户评价'){
          this.setData({
            ping: true
          })
        };
        if(res.data.ddzt=='订单已完成'){
          this.setData({
            pingjia: true
          })
        };
        if(res.data.ddzt=='等待客户支付'){
          this.setData({
            zhifu: true
          })
        };
      }
    })
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