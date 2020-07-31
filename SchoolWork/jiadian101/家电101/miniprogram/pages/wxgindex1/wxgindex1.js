// miniprogram/pages/wxgindex1/wxgindex1.js
//云数据库初始化
const db = wx.cloud.database({});
const order = db.collection('order');
var app = getApp();

Page({
/**
 * 页面的初始数据
 */
data: {
  currtab: 0,
  swipertab: [{ name: '未接单', index: 0 }, { name: '已接单', index: 1 },{name:'已完成',index:2}],
  donelist:[],
  todolist:[],
  list:[],
  username:'',
},


/**
 * 生命周期函数--监听页面加载
 */
onLoad: function (options) {
  
},

onShow: function () {
  this.setData({
    username: app.globalData.globalName
  })
  order.where({
    repname: this.data.username,
    status: '未完成',
  }).get({
    success: res=>{
      this.setData({
        todolist:res.data
      })
    }
  }),
  order.where({
    repname: this.data.username,
    status:"已完成",
  }).get({
    success: res=>{
      this.setData({
        donelist:res.data
      })
    }
  }),
  order.where({
    ddzt:"等待维修工接单",
  }).get({
    success: res=>{
      this.setData({
        list:res.data
      })
    }
  })
},

/**
 * 生命周期函数--监听页面初次渲染完成
 */
onReady: function () {
  // 页面渲染完成
  this.getDeviceInfo()
},


getDeviceInfo: function () {
  let that = this
  wx.getSystemInfo({
    success: function (res) {
      that.setData({
        deviceW: res.windowWidth,
        deviceH: res.windowHeight
      })
    }
  })
},


/**
* @Explain：选项卡点击切换
*/
tabSwitch: function (e) {
  var that = this
  if (this.data.currtab === e.target.dataset.current) {
    return false
  } else {
    that.setData({
      currtab: e.target.dataset.current
    })
  }
},


tabChange: function (e) {
  this.setData({ currtab: e.detail.current })
},

orderdetails: function(e){
  var id = e.currentTarget.dataset.id;
  wx.navigateTo({
    url: '../wxgdetails/wxgdetails?id='+id,
  })
},


})
